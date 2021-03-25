/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:21:34 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/14 10:52:02 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_scale_minimap(t_image *img, int i, int j, int color)
{
    int x;
    int y;

    i *= SCALE;
    j *= SCALE;
    x = j;
    while (x < (j + SCALE))
    {
        y = i;
        while (y < (i + SCALE))
        {
            my_pixel_put(img, x, y, color);
            y++;
        }
        x++;
    }
}

void    ft_draw_minimap(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;

    while (mlx->cfg.map[i])
    {
        j = 0;
        while (j < ft_strlen(mlx->cfg.map[i]))
	    {
            if (mlx->cfg.map[i][j] == '1')
                ft_scale_minimap(&mlx->img, i, j, 0xffffffff);
            else
                ft_scale_minimap(&mlx->img, i, j, 0xff000000);
            j++;
        }
        i++;
    }
    my_pixel_put(&mlx->img, (mlx->ray.posX * SCALE), (mlx->ray.posY * SCALE + SCALE / 2), 0x00ff0000);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img, 0, 0);
}