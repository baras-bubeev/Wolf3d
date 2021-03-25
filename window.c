/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:03:02 by baras             #+#    #+#             */
/*   Updated: 2021/03/25 09:46:52 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     ft_x_press(t_mlx *mlx)
{
    int	i;

	free(mlx->allspr.spr);
	free(mlx->allspr.z_buffer);
	i = 0;
	while (i < mlx->cfg.map_size)
		free(mlx->cfg.map[i++]);
	free(mlx->cfg.map);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	exit(0);
}

static void ft_load_tex(t_texture *tex, void *mlx_ptr, char **fname)
{
    (!(tex->tex_ptr = mlx_xpm_file_to_image(mlx_ptr, *fname, &tex->width, 
        &tex->height))) ? ft_exit(1, TEXTURE_ERROR) : 0;
    tex->addr = mlx_get_data_addr(tex->tex_ptr, &tex->bpp, 
        &tex->line_len, &tex->end);
    free(*fname);
}

void    ft_window(t_mlx *mlx)
{
    mlx->mlx_ptr = mlx_init();
    mlx_get_screen_size(mlx->mlx_ptr, &mlx->max_x, &mlx->max_y);
    (mlx->cfg.r[0] > mlx->max_x) ? mlx->cfg.r[0] = mlx->max_x : 0;
    (mlx->cfg.r[1] > mlx->max_y) ? mlx->cfg.r[1] = mlx->max_y : 0;
    (mlx->save == 0) ? mlx->win = mlx_new_window(mlx->mlx_ptr,
        mlx->cfg.r[0], mlx->cfg.r[1], "by mpowder") : 0;
    mlx->img.img = mlx_new_image(mlx->mlx_ptr, mlx->cfg.r[0], mlx->cfg.r[1]);
    mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
        &mlx->img.line_len, &mlx->img.end);
    ft_load_tex(&mlx->no_tex, mlx->mlx_ptr, &mlx->cfg.no);
    ft_load_tex(&mlx->so_tex, mlx->mlx_ptr, &mlx->cfg.so);
    ft_load_tex(&mlx->we_tex, mlx->mlx_ptr, &mlx->cfg.we);
    ft_load_tex(&mlx->ea_tex, mlx->mlx_ptr, &mlx->cfg.ea);
    ft_load_tex(&mlx->sp_tex, mlx->mlx_ptr, &mlx->cfg.s);
    ft_var_init(mlx);
    ft_raycast(mlx);
	// ft_draw_minimap(&mlx); 
	mlx_hook(mlx->win, 33, 0, ft_x_press, mlx);
	mlx_hook(mlx->win, 2, 1L<<0, ft_keypress, mlx);
    // mlx_loop_hook(mlx->mlx_ptr, &ft_game_loop, &mlx);
    mlx_loop(mlx->mlx_ptr);
}
