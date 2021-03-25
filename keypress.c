/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:45:34 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/25 13:34:25 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_up_down_key(int key, t_mlx *mlx, double mvSpeed, double er)
{
    if (key == W_KEY || key == UP_KEY)
    {
        if (mlx->cfg.map[(int)(mlx->ray.ypos + mlx->ray.ydir * (mvSpeed + er))]
        [(int)mlx->ray.xpos] == '0')
            mlx->ray.ypos += mlx->ray.ydir * mvSpeed;
        if (mlx->cfg.map[(int)mlx->ray.ypos][(int)(mlx->ray.xpos + 
        mlx->ray.xdir * (mvSpeed + er))] == '0')
            mlx->ray.xpos += mlx->ray.xdir * mvSpeed;
    }
    if (key == S_KEY || key == DOWN_KEY)
    {
        if (mlx->cfg.map[(int)(mlx->ray.ypos - mlx->ray.ydir * (mvSpeed + er))]
        [(int)mlx->ray.xpos] == '0')
            mlx->ray.ypos -= mlx->ray.ydir * mvSpeed;
        if (mlx->cfg.map[(int)mlx->ray.ypos][(int)(mlx->ray.xpos - 
        mlx->ray.xdir * (mvSpeed + er))] == '0')
            mlx->ray.xpos -= mlx->ray.xdir * mvSpeed;
    }
}

static void ft_a_d_key(int key, t_mlx *mlx, double mvSpeed, double er)
{
    if (key == A_KEY)
    {
        if (mlx->cfg.map[(int)(mlx->ray.ypos - mlx->ray.ypln * (mvSpeed + er))]
        [(int)mlx->ray.xpos] == '0')
            mlx->ray.ypos -= mlx->ray.ypln * mvSpeed;
        if (mlx->cfg.map[(int)mlx->ray.ypos][(int)(mlx->ray.xpos - 
        mlx->ray.xpln * (mvSpeed + er))] == '0')
            mlx->ray.xpos -= mlx->ray.xpln * mvSpeed;
    }
    if (key == D_KEY)
    {
        if (mlx->cfg.map[(int)(mlx->ray.ypos + mlx->ray.ypln * (mvSpeed + er))]
        [(int)mlx->ray.xpos] == '0')
            mlx->ray.ypos += mlx->ray.ypln * mvSpeed;
        if (mlx->cfg.map[(int)mlx->ray.ypos][(int)(mlx->ray.xpos + 
        mlx->ray.xpln * (mvSpeed + er))] == '0')
            mlx->ray.xpos += mlx->ray.xpln * mvSpeed;
    }
}

static void ft_left_right_key(int key, t_mlx *mlx, double rSpeed)
{
    double  oldDir;
    double  oldPlane;
    double  rSin;
    double  rCos;
    
    oldDir = mlx->ray.xdir;
    oldPlane = mlx->ray.xpln;
    rSin = sin(rSpeed);
    rCos = cos(rSpeed);
    mlx->ray.xdir = mlx->ray.xdir * rCos - mlx->ray.ydir * rSin;
    mlx->ray.ydir = oldDir * rSin + mlx->ray.ydir * rCos;
    mlx->ray.xpln = mlx->ray.xpln * rCos - mlx->ray.ypln * rSin;
    mlx->ray.ypln = oldPlane * rSin + mlx->ray.ypln * rCos;
}

int  ft_keypress(int key, t_mlx *mlx)
{
    double  mvSpeed;
    double  rSpeed;
    double  er;

    mvSpeed = 0.1;
    rSpeed = 0.05;
    er = 0.3;
    if (key == ESC_KEY)
        ft_x_press(mlx);
    if (key == W_KEY || key == UP_KEY || key == S_KEY || key == DOWN_KEY)
        ft_up_down_key(key, mlx, mvSpeed, er);
    if (key == A_KEY || key == D_KEY)
        ft_a_d_key(key, mlx, mvSpeed, er);
    if (key == LEFT_KEY)
        ft_left_right_key(key, mlx, rSpeed);
    if (key == RIGHT_KEY)
        ft_left_right_key(key, mlx, -rSpeed);
    ft_raycast(mlx);
    // ft_draw_minimap(mlx);
    return (1);
}
