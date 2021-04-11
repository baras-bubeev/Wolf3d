#include "cub3d.h"

static void	ft_sprite_sort(t_allspr *allspr)
{
	int	i;
	int	j;
	t_sprite tmp;

	i = -1;
	while (++i < allspr->spr_num)
	{
		j = -1;
		while (++j < allspr->spr_num - 1 - i)
		{
			if (allspr->spr[j].dist < allspr->spr[j + 1].dist)
			{
				tmp = allspr->spr[j];
				allspr->spr[j] = allspr->spr[j + 1];
				allspr->spr[j + 1] = tmp;
			}
		}
	}
}

static void	ft_sprite_calc(t_allspr *all, t_raycast *ray, int i, int *r)
{
	all->xspr = all->spr[i].x - ray->xpos;
	all->yspr = all->spr[i].y - ray->ypos;
	all->det = 1.0 / (ray->xpln * ray->ydir - ray->xdir * ray->ypln);
	all->xtrns = all->det * (ray->ydir * all->xspr - ray->xdir * all->yspr);
	all->ytrns = all->det * (ray->xpln * all->yspr - ray->ypln * all->xspr);
	all->spr_screen_x = (int)((r[0] / 2) * (1 + all->xtrns / all->ytrns));
	all->spr_size = abs((int)(r[1] / all->ytrns)) / SPRITE_SCALE;
	all->draw_start_y = r[1] / 2 - all->spr_size / 2;//
	(all->draw_start_y < 0) ? all->draw_start_y = 0 : 0;
	all->draw_end_y = r[1] / 2 + all->spr_size / 2;//
	(all->draw_end_y >= r[1]) ? all->draw_end_y = r[1] - 1 : 0;
	all->draw_start_x = all->spr_screen_x - all->spr_size / 2;
	(all->draw_start_x < 0) ? all->draw_start_x = 0 : 0;
	all->draw_end_x = all->spr_screen_x + all->spr_size / 2;
	(all->draw_end_x >= r[0]) ? all->draw_end_x = r[0] - 1 : 0;
}

static void	ft_sprite_draw(t_mlx *mlx, t_allspr *all)
{
	int	y;
	int	d;
	int	color;

	all->stripe = all->draw_start_x - 1;
	while (++all->stripe < all->draw_end_x)
	{
		all->xtex = (int)(256 * (all->stripe - (all->spr_screen_x
		- all->spr_size / 2)) * mlx->sp_tex.width / all->spr_size / 256);
		if (all->ytrns > 0 && all->stripe > 0 && all->stripe < mlx->cfg.r[0]
		&& all->ytrns < all->z_buffer[all->stripe])
		{
			y = all->draw_start_y - 1;
			while (++y < all->draw_end_y)
			{
				d = y * 256 - mlx->cfg.r[1] * 128 + all->spr_size * 128;
				all->ytex = d * mlx->sp_tex.height / all->spr_size / 256;
				color = (*(int *)(mlx->sp_tex.addr + (all->ytex 
				* mlx->sp_tex.width + all->xtex) * (mlx->sp_tex.bpp / 8)));
				if ((color & 0x00ffffff) != 0)
					my_pixel_put(&mlx->img, all->stripe, y, color);
			}
		}
	}
}

void	ft_sprite(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->allspr.spr_num)
	{
		mlx->allspr.spr[i].dist = pow(mlx->ray.xpos - mlx->allspr.spr[i].x, 2);
		mlx->allspr.spr[i].dist += pow(mlx->ray.ypos - mlx->allspr.spr[i].y, 2);
	}
	ft_sprite_sort(&mlx->allspr);
	i = -1;
	while (++i < mlx->allspr.spr_num)
	{
		ft_sprite_calc(&mlx->allspr, &mlx->ray, i, mlx->cfg.r);
		ft_sprite_draw(mlx, &mlx->allspr);
	}
	if (mlx->save == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img, 0, 0);
	else
		ft_screen(mlx);
}
