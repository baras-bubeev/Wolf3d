/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:21:34 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/25 13:33:44 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_dir_init(t_mlx *mlx, int i, int j)
{
    if (mlx->cfg.map[i][j] == 'N')
    {
        mlx->ray.ydir = -1;
        mlx->ray.xpln = -0.66;
    }
    if (mlx->cfg.map[i][j] == 'S')
    {
        mlx->ray.ydir = 1;
        mlx->ray.xpln = 0.66;
    }
    if (mlx->cfg.map[i][j] == 'W')
    {
        mlx->ray.xdir = -1;
        mlx->ray.ypln = 0.66;
    }
    if (mlx->cfg.map[i][j] == 'E')
    {
        mlx->ray.xdir = 1;
        mlx->ray.ypln = -0.66;
    }
}

void    ft_var_init(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    mlx->ray.xdir = 0;
    mlx->ray.ydir = 0;
    mlx->ray.xpln = 0;
    mlx->ray.ypln = 0;
    while (mlx->cfg.map[i])
    {
        j = 0;
        while (j < ft_strlen(mlx->cfg.map[i]))
	    {
            if (ft_strchr(DIRECTION, mlx->cfg.map[i][j]))
            {
                mlx->ray.xpos = (double)j + 0.5;
                mlx->ray.ypos = (double)i + 0.5;
                ft_dir_init(mlx, i, j);
                mlx->cfg.map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
}