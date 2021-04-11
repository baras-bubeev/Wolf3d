#include "cub3d.h"

static int	ft_color_init(t_mlx *mlx)
{
	int	color;

	if (mlx->ray.side && mlx->ray.r_dir_y < 0)
		color = (*(int *)(mlx->no_tex.addr + (mlx->ray.ytex
			* mlx->no_tex.width + mlx->ray.xtex) * (mlx->no_tex.bpp / 8)));
	if (mlx->ray.side && mlx->ray.r_dir_y > 0)
		color = (*(int *)(mlx->so_tex.addr + (mlx->ray.ytex
			* mlx->so_tex.width + mlx->ray.xtex) * (mlx->so_tex.bpp / 8)));
	if (!mlx->ray.side && mlx->ray.r_dir_x < 0)
		color = (*(int *)(mlx->ea_tex.addr + (mlx->ray.ytex
			* mlx->ea_tex.width + mlx->ray.xtex) * (mlx->ea_tex.bpp / 8)));
	if (!mlx->ray.side && mlx->ray.r_dir_x > 0)
	{
		color = (*(int *)(mlx->we_tex.addr + (mlx->ray.ytex
			* mlx->we_tex.width + mlx->ray.xtex) * (mlx->we_tex.bpp / 8)));
		color = (color >> 1) & 8355711;
	}
	return (color);
}

static void	ft_draw_line(int x, t_mlx *mlx)
{
	int	y;
	int	f_color;
	int	c_color;
	int	w_color;

	y = 0;
	f_color = mlx->cfg.f[0] << 16 | mlx->cfg.f[1] << 8 | mlx->cfg.f[2];
	c_color = mlx->cfg.c[0] << 16 | mlx->cfg.c[1] << 8 | mlx->cfg.c[2];
	while (y < mlx->ray.draw_start)
		my_pixel_put(&mlx->img, x, y++, c_color);
	while (y <= mlx->ray.draw_end && y < mlx->cfg.r[1])
	{
		mlx->ray.ytex = (int)mlx->ray.tex_pos & (mlx->ray.htex - 1);
		mlx->ray.tex_pos += mlx->ray.step;
		w_color = ft_color_init(mlx);
		my_pixel_put(&mlx->img, x, y++, w_color);
	}
	while (y < mlx->cfg.r[1])
		my_pixel_put(&mlx->img, x, y++, f_color);
}

void		ft_texture(t_mlx *mlx, int x)
{
	mlx->ray.xwall = (mlx->ray.side == 0) ?
		mlx->ray.ypos + mlx->ray.perp_wall_dist * mlx->ray.r_dir_y :
		mlx->ray.xpos + mlx->ray.perp_wall_dist * mlx->ray.r_dir_x;
	mlx->ray.xwall -= floor(mlx->ray.xwall);
	mlx->ray.xtex = (int)(mlx->ray.xwall * (double)mlx->ray.wtex);
	if (mlx->ray.side == 0 && mlx->ray.r_dir_x > 0)
		mlx->ray.xtex = mlx->ray.wtex - mlx->ray.xtex - 1;
	if (mlx->ray.side == 1 && mlx->ray.r_dir_y < 0)
		mlx->ray.xtex = mlx->ray.wtex - mlx->ray.xtex - 1;
	mlx->ray.step = (double)mlx->ray.htex / mlx->ray.line_height;
	mlx->ray.tex_pos = (mlx->ray.draw_start - mlx->cfg.r[1] / 2
		+ mlx->ray.line_height / 2) * mlx->ray.step;
	ft_draw_line(x, mlx);
}
