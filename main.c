/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:50:27 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/11 00:42:27 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_file_read(char *fname, char **config)
{
	int		fd;
	int		byte;
	char	buf[1024];
	int		fsize;

	fsize = 0;
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	while ((byte = read(fd, buf, 1024)))
		fsize += byte;
	close(fd);
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	if (!(*config = (char *)malloc(sizeof(*config) * (fsize + 1))))
		return(-1);
	if (read(fd, *config, fsize) < 0)
		return (-1);
	(*config)[fsize] = 0;
	close(fd);
	return (fsize);
}

int		main(int argc, char **argv)
{
	char	*config;
	// char	**map;
	(void)argc;

	if (ft_file_read(argv[1], &config) < 0)
		return (-1);
	printf("%s\n", config);
	ft_parsing(config);
}