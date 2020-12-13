/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:42:05 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/13 06:22:37 by mpowder          ###   ########.fr       */
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

# define OPEN_ERROR "Error\nOpen"
# define CLOSE_ERROR "Error\nClose"
# define READ_ERROR "Error\nRead"
# define MALLOC_ERROR "Error\nMemory allocation"
# define NOT_VALID_FILE "Error\nNot a valid scene description file"

int		main(int argc, char **argv);
void	ft_parsing(char **map);
void	ft_exit(int n, char *str);

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
}				t_parse;


#endif