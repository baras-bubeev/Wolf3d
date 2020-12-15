/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:50:27 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/15 02:05:06 by mpowder          ###   ########.fr       */
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
	(fsize < 46) ? ft_exit(1, NOT_VALID_FILE) : 0;
	(close(fd) < 0) ? ft_exit(-1, CLOSE_ERROR) : 0;
	((fd = open(fname, O_RDONLY)) < 0) ? ft_exit(fd, OPEN_ERROR) : 0;
	(!(*config = (char *)malloc(sizeof(*config) * (fsize + 1)))) ?
		ft_exit(-1, MALLOC_ERROR) : 0;
	(read(fd, *config, fsize) < 0) ? ft_exit(-1, READ_ERROR) : 0;
	(*config)[fsize--] = 0;
	while ((*config)[fsize] == ' ')
		fsize--;
	((*config)[fsize] != '1') ? ft_exit(1, NOT_VALID_FILE) : 0;
	(close(fd) < 0) ? ft_exit(-1, CLOSE_ERROR) : 0;
}

int			main(int argc, char **argv)
{
	char	*config;
	char	**map;

	(argc > 1 && ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), FILE_TYPE, 5)) ?
		ft_exit(1, NOT_VALID_TYPE) : 0;
	ft_file_read(argv[1], &config);
	ft_parsing(&map, config);
	free(config);
	ft_map_validation(map);
	return (0);
}

	// i = 0;
	// while (i < 8)
	// 	free(map[i++]);
	// map += 8;
	// ft_map_validation(map);

	// printf("\n**************************\n");
	// printf("x = |%d|\ny = |%d|\n", cfg.r[0], cfg.r[1]);
	// printf("no = |%s|\n", cfg.no);
	// printf("so = |%s|\n", cfg.so);
	// printf("we = |%s|\n", cfg.we);
	// printf("ea = |%s|\n", cfg.ea);
	// printf(" s = |%s|\n", cfg.s);
	// printf("***F***\n");
	// printf("R = |%3d|\nG = |%3d|\nB = |%3d|\n", cfg.f[0], cfg.f[1], cfg.f[2]);
	// printf("***C***\n");
	// printf("R = |%3d|\nG = |%3d|\nB = |%3d|\n", cfg.c[0], cfg.c[1], cfg.c[2]);
	// while (*map)
	// printf("%s\n", *map++);