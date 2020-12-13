/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:50:27 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/13 07:35:38 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_file_read(char *fname, char **config)
{
	int		fd;
	int		byte;
	char	buf[1024];
	int		fsize;

	fsize = 0;
	((fd = open(fname, O_RDONLY)) < 0) ? ft_exit(fd, OPEN_ERROR) : 0;
	while ((byte = read(fd, buf, 1024)) > 0)
		fsize += byte;
	(byte < 0) ? ft_exit(byte, READ_ERROR) : 0;
	(fsize < 46) ? ft_exit(0, NOT_VALID_FILE) : 0;
	(close(fd) < 0) ? ft_exit(-1, CLOSE_ERROR) : 0;
	((fd = open(fname, O_RDONLY)) < 0) ? ft_exit(fd, OPEN_ERROR) : 0;
	(!(*config = (char *)malloc(sizeof(*config) * (fsize + 1)))) ?
		ft_exit(1, MALLOC_ERROR) : 0;
	(read(fd, *config, fsize) < 0) ? ft_exit(-1, READ_ERROR) : 0;
	(*config)[fsize--] = 0;
	while ((*config)[fsize] == ' ')
		fsize--;
	((*config)[fsize] != '1') ? ft_exit(0, NOT_VALID_FILE) : 0;
	(close(fd) < 0) ? ft_exit(-1, CLOSE_ERROR) : 0;
}

int			main(int argc, char **argv)
{
	char	*config;
	char	**map;
	int		i;

	(void)argc;
	i = -1;
	ft_file_read(argv[1], &config);
	(!(map = ft_split(config, '\n'))) ? ft_exit(1, MALLOC_ERROR) : 0;
	free(config);
	while (++i < 8)
		(!(map[i] = ft_strtrim_free(&map[i], " \t"))) ?
			ft_exit(1, MALLOC_ERROR) : 0;
	ft_parsing(map);
	return (0);
}
