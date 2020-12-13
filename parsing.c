/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:42:54 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/13 07:23:54 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_texture(char *src, char **dst)
{
	// int		fd;

	(*dst) ? ft_exit(0, NOT_VALID_FILE) : 0;
	(ft_strlen(src) < 3) ? ft_exit(0, NOT_VALID_FILE) : 0;
	(*(++src) != ' ') ? ft_exit(0, NOT_VALID_FILE) : 0;
	while (*src && *src == ' ')
		src++;
	(!(*dst = ft_strdup(src))) ? ft_exit(1, MALLOC_ERROR) : 0;
	// ((fd = open(*dst, O_RDONLY)) < 0) ? ft_exit(-1, OPEN_ERROR) : 0;
	// (close(fd) < 0) ? ft_exit(fd, CLOSE_ERROR) : 0;
}

static void	ft_num(char *src, int *dst, char c)
{
	int		i;
	int		max;

	i = 0;
	max = (c == 'R') ? 2 : 3;
	while (i < max)
	{
		(max == 2 && dst[i] != 0) ? ft_exit(0, NOT_VALID_FILE) : 0;
		(max == 3 && dst[i] != -1) ? ft_exit(0, NOT_VALID_FILE) : 0;
		while (*src == ' ')
			src++;
		(!ft_isdigit(*src)) ? ft_exit(0, NOT_VALID_FILE) : 0;
		dst[i] = *src - '0';
		while (ft_isdigit(*(++src)))
			dst[i] = dst[i] * 10 + (*src - '0');
		(max == 3 && *src == ',') ? src++ : 0;
		(max == 2 && dst[i] <= 0) ? ft_exit(0, NOT_VALID_FILE) : 0;
		(max == 3 && (dst[i] < 0 || dst[i] > 255)) ?
			ft_exit(0, NOT_VALID_FILE) : 0;
		i++;
	}
}

static void	ft_get_config(char **map, t_parse *cfg)
{
	int		i;

	i = 0;
	while (map[i] && i < 8 && *map[i])
	{
		if (*map[i] == 'N' && *(map[i] + 1) == 'O')
			ft_texture(map[i] + 1, &cfg->no);
		else if (*map[i] == 'S' && *(map[i] + 1) == 'O')
			ft_texture(map[i] + 1, &cfg->so);
		else if (*map[i] == 'W' && *(map[i] + 1) == 'E')
			ft_texture(map[i] + 1, &cfg->we);
		else if (*map[i] == 'E' && *(map[i] + 1) == 'A')
			ft_texture(map[i] + 1, &cfg->ea);
		else if (*map[i] == 'S' && *(map[i] + 1) == ' ')
			ft_texture(map[i], &cfg->s);
		else if (*map[i] == 'R' && *(map[i] + 1) == ' ')
			ft_num(map[i] + 1, cfg->r, *map[i]);
		else if (*map[i] == 'F' && *(map[i] + 1) == ' ')
			ft_num(map[i] + 1, cfg->f, *map[i]);
		else if (*map[i] == 'C' && *(map[i] + 1) == ' ')
			ft_num(map[i] + 1, cfg->c, *map[i]);
		else
			ft_exit(0, NOT_VALID_FILE);
		i++;
	}
}

void		ft_parsing(char **map)
{
	t_parse	cfg;
	int		i;

	cfg.r[0] = 0;
	cfg.r[1] = 0;
	cfg.no = 0;
	cfg.so = 0;
	cfg.we = 0;
	cfg.ea = 0;
	cfg.s = 0;
	cfg.f[0] = -1;
	cfg.f[1] = -1;
	cfg.f[2] = -1;
	cfg.c[0] = -1;
	cfg.c[1] = -1;
	cfg.c[2] = -1;
	ft_get_config(map, &cfg);
	i = 0;
	while (i < 8)
		free(map[i++]);
	map += 8;
}
