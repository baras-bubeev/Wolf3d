/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 23:42:05 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/11 03:45:55 by mpowder          ###   ########.fr       */
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

int		main(int argc, char **argv);
int		ft_parsing(char *cfg);

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