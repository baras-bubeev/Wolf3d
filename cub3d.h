/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:42:05 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/25 09:47:00 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include "mlx_int.h"

# define FILE_TYPE ".cub"
# define SAVE "--save"
# define OPEN_ERROR "Error\nOpen"
# define CREATE_ERROR "Error\nCreate"
# define CLOSE_ERROR "Error\nClose"
# define READ_ERROR "Error\nRead"
# define MALLOC_ERROR "Error\nMemory allocation"
# define NO_FILE "Error\nNo config file"
# define NOT_VALID_FILE "Error\nNot a valid scene description file"
# define NOT_VALID_ARG "Error\nNot a valid second argument"
# define TOO_MANY_ARG "Error\nToo many arguments"
# define NOT_VALID_TYPE "Error\nNot a valid file extension"
# define TEXTURE_ERROR "Error\nNot a valid texture filename"
# define MAP_ERROR "Error\nNot a valid map"
# define IDENTIFIER "NWESRFC \n"
# define POSSIBLE " 012NWES"
# define PERMITTED "NWES02"
# define DIRECTION "NWES"
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361	
# define RIGHT_KEY 65363
# define SCALE 10
# define SPRITE_SCALE 1

typedef struct	s_parse
{
	int			r[2];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f[3];
	int			c[3];
	char		**map;
	int			map_size;
}				t_parse;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			end;
}				t_image;

typedef struct	s_raycast
{
	// вектор положения игрока
	double		xpos;
	double		ypos;
	// направление игрока
	double		xdir;
	double		ydir;
	// плоскость камеры игрока
	double		xpln;
	double		ypln;
	// координа Х на плоскости камеры
	double		cmr_x;
	// направление луча
	double		r_dir_x;
	double		r_dir_y;
	// квадрат карты, в которой находится луч
	int			xmap;
	int			ymap;
	// изначальное расстояние, которое должен пройти луч от его начальной позиции до первой стороны х и у
	double		xside_dist;
	double		yside_dist;
	// это расстояние, которое должен пройти луч, чтобы перейти от 1 стороны x к следующей стороне x или от 1 стороны y к следующей стороне y.
	double		xdelta_dist;
	double		ydelta_dist;
	// используется для вычисления длины луча
	double		perp_wall_dist;
	int			xstep;
	int			ystep;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		xwall;
	int			wtex;
	int			htex;
	int			xtex;
	int			ytex;
	double		step;
	double		tex_pos;
}				t_raycast;

typedef struct	s_texture
{
	void		*tex_ptr;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			line_len;
	int			end;
}				t_texture;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

typedef struct	s_allspr
{
	t_sprite	*spr;
	int			spr_num;
	double		*z_buffer;
	double		xspr;
	double		yspr;
	double		det;
	double		xtrns;
	double		ytrns;
	int			spr_screen_x;
	int			spr_size;
	int			draw_start_x;
	int			draw_end_x;
	int			draw_start_y;
	int			draw_end_y;
	int			stripe;
	int			xtex;
	int			ytex;
}				t_allspr;
typedef struct	s_mlx
{
	int			save;
	void		*mlx_ptr;
	void		*win;
	int			max_x;
	int			max_y;
	t_image		img;
	t_parse		cfg;
	t_raycast	ray;
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;                                              
	t_texture	ea_tex;
	t_texture	sp_tex;
	t_allspr	allspr;
}				t_mlx;

int		main(int argc, char **argv);
void	ft_parsing(char *str, t_parse *cfg);
void	ft_exit(int n, char *str);
int		ft_map_validation(char **map);
void    ft_window(t_mlx *mlx);
void    my_pixel_put(t_image *img, int x, int y, int color);
int		ft_keypress(int key, t_mlx *mlx);
void    ft_var_init(t_mlx *mlx);
void    ft_draw_minimap(t_mlx *mlx);
void    ft_raycast(t_mlx *mlx);
void	ft_texture(t_mlx *mlx, int x);
void	ft_sprite(t_mlx *mlx);
void	ft_screen(t_mlx *mlx);
int     ft_x_press(t_mlx *mlx);

#endif