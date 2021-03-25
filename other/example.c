/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:03:02 by baras             #+#    #+#             */
/*   Updated: 2021/02/25 16:39:42 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_int.h"
#include <stdlib.h>

typedef struct  s_mlx {
        void    *mlx;
        void    *win;
}               t_mlx;

int    ft_exit(int key, t_mlx *mlx)
{
	printf("aaaa");
	printf("%d\n", key);
	if (key == 65307)				// "65307" - код клавиши 'esc'
	{
    	mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (1);
}

int		main(void)
{
	t_mlx	mlx;
    int		max_x;
	int		max_y;
	int		x = 500;
	int		y = 500;

    mlx.mlx = mlx_init();
	mlx_get_screen_size(mlx.mlx, &max_x, &max_y);
	(x > max_x) ? x = max_x : 0;
	(y > max_y) ? y = max_y : 0;
    mlx.win = mlx_new_window(mlx.mlx, x, y, "cub3d by mpowder");
	mlx_key_hook(mlx.win, ft_exit, &mlx);
	mlx_hook(mlx.win, 17, (1L<<17), ft_exit, &mlx);
    mlx_loop(mlx.mlx);
    return (0);
}