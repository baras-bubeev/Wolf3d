/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:32:17 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/25 09:25:02 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_init(t_raycast *ray, int h, int w)
{
	double	rat;

	rat = (w / h < 1) ? 1 : w / h;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->xmap - ray->xpos + (1 - ray->xstep) / 2)
		/ ray->r_dir_x;
	else
		ray->perp_wall_dist = (ray->ymap - ray->ypos + (1 - ray->ystep) / 2)
		/ ray->r_dir_y;
	ray->line_height = (int)(h * rat / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + h / 2;
	if (ray->draw_end >= h)
		ray->draw_end = h - 1;
}

static void	ft_dda(t_mlx *mlx)
{
	while (mlx->cfg.map[mlx->ray.ymap][mlx->ray.xmap] != '1')
	{
		if (mlx->ray.xside_dist < mlx->ray.yside_dist)
		{
			mlx->ray.xside_dist += mlx->ray.xdelta_dist;
			mlx->ray.xmap += mlx->ray.xstep;
			mlx->ray.side = 0;
		}
		else
		{
			mlx->ray.yside_dist += mlx->ray.ydelta_dist;
			mlx->ray.ymap += mlx->ray.ystep;
			mlx->ray.side = 1;
		}
	}
}

static void	ft_step_calc(t_raycast *ray)
{
	if (ray->r_dir_y == 0)
		ray->xdelta_dist = 0;
	else
		ray->xdelta_dist = (ray->r_dir_x == 0) ? 1 : fabs(1 / ray->r_dir_x);
	if (ray->r_dir_x == 0)
		ray->ydelta_dist = 0;
	else
		ray->ydelta_dist = (ray->r_dir_y == 0) ? 1 : fabs(1 / ray->r_dir_y);
	if (ray->r_dir_x < 0 && (ray->xstep = -1))
		ray->xside_dist = (ray->xpos - ray->xmap) * ray->xdelta_dist;
	else
	{
		ray->xstep = 1;
		ray->xside_dist = (ray->xmap + 1.0 - ray->xpos) * ray->xdelta_dist;
	}
	if (ray->r_dir_y < 0 && (ray->ystep = -1))
		ray->yside_dist = (ray->ypos - ray->ymap) * ray->ydelta_dist;
	else
	{
		ray->ystep = 1;
		ray->yside_dist = (ray->ymap + 1.0 - ray->ypos) * ray->ydelta_dist;
	}
}

void		ft_raycast(t_mlx *mlx)
{
	int	x;

	x = -1;
	mlx->ray.htex = 64;
	mlx->ray.wtex = 64;
	while (++x < mlx->cfg.r[0])
	{
		mlx->ray.cmr_x = 2 * x / (double)mlx->cfg.r[0] - 1;
		mlx->ray.r_dir_x = mlx->ray.xdir + mlx->ray.xpln * mlx->ray.cmr_x;
		mlx->ray.r_dir_y = mlx->ray.ydir + mlx->ray.ypln * mlx->ray.cmr_x;
		mlx->ray.xmap = (int)mlx->ray.xpos;
		mlx->ray.ymap = (int)mlx->ray.ypos;
		ft_step_calc(&mlx->ray);
		ft_dda(mlx);
		ft_draw_init(&mlx->ray, mlx->cfg.r[1], mlx->cfg.r[0]);
		ft_texture(mlx, x);
		mlx->allspr.z_buffer[x] = mlx->ray.perp_wall_dist;
	}
	ft_sprite(mlx);
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img, 0, 0);
}
