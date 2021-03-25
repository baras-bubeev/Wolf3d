/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:50:27 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/25 13:32:33 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free(t_mlx *mlx)
{
	int	i;

	free(mlx->allspr.spr);
	free(mlx->allspr.z_buffer);
	i = 0;
	while (i < mlx->cfg.map_size)
		free(mlx->cfg.map[i++]);
	free(mlx->cfg.map);
}

static void	ft_sprite_pos(t_allspr *allspr, char **map)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '2')
			{
				allspr->spr[x].x = (double)j + 0.5;
				allspr->spr[x].y = (double)i + 0.5;
				x++; 
			}
		}
	}
}

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
	t_mlx	mlx;

	mlx.save = 0;
	(argc == 1) ? ft_exit(1, NO_FILE) : 0;
	(ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), FILE_TYPE, 5)) ?
		ft_exit(1, NOT_VALID_TYPE) : 0;
	if (argc == 3)
		if (ft_strncmp(argv[2], SAVE, 7))
			ft_exit(1, NOT_VALID_ARG);
		else
			mlx.save = 1;
	(argc > 3) ? ft_exit(1, TOO_MANY_ARG) : 0;
	ft_file_read(argv[1], &config);
	ft_parsing(config, &mlx.cfg);
	free(config);
	mlx.allspr.spr_num = ft_map_validation(mlx.cfg.map);
	(!(mlx.allspr.spr = (t_sprite *)malloc(sizeof(t_sprite)
		* mlx.allspr.spr_num)))	? ft_exit(-1, MALLOC_ERROR) : 0;
	ft_sprite_pos(&mlx.allspr, mlx.cfg.map);
	(!(mlx.allspr.z_buffer = (double *)malloc(sizeof(mlx.allspr.z_buffer)
		* mlx.cfg.r[0]))) ? ft_exit(-1, MALLOC_ERROR) : 0;
	ft_window(&mlx);
	ft_free(&mlx);
	return (0);
}
