/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:45:08 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/15 14:20:32 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_map_size(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

static void	ft_border(char **map, int size)
{
	int	i;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != ' ' && map[0][i] != '1')
			ft_exit(1, MAP_ERROR);
	i = -1;
	while (map[size - 1][++i])
		if (map[size - 1][i] != ' ' && map[size - 1][i] != '1')
			ft_exit(1, MAP_ERROR);
	i = -1;
	while (++i < size)
	{
		if (map[i][0] != ' ' && map[i][0] != '1')
			ft_exit(1, MAP_ERROR);
		if (map[i][ft_strlen(map[i]) - 1] != ' '
			&& map[i][ft_strlen(map[i]) - 1] != '1')
			ft_exit(1, MAP_ERROR);
	}
}

static void	ft_map_close(char **map, int size, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr(PERMITTED, map[i][j]))
			{
				if (map[i][j - 1] == c ||
					map[i][j + 1] == c ||
					map[i - 1][j - 1] == c ||
					map[i - 1][j] == c ||
					map[i - 1][j + 1] == c ||
					map[i + 1][j - 1] == c ||
					map[i + 1][j] == c ||
					map[i + 1][j + 1] == c)
					ft_exit(1, MAP_ERROR);
			}
		}
	}
}

static int	ft_check_plr(char **map, int size)
{
	int	i;
	int	j;
	int plr;
	int	count;

	i = -1;
	plr = 0;
	count = 0;
	while (++i < size)
	{
		j = -1;
		while (map[i][++j])
		{
			(ft_strchr(DIRECTION, map[i][j])) ? plr++ : 0;
			if (!ft_strchr(POSSIBLE, map[i][j]))
				ft_exit(1, MAP_ERROR);
			(map[i][j] == '2') ? count++ : 0;
		}
	}
	(plr != 1) ? ft_exit(1, MAP_ERROR) : 0;
	return (count);
}

int			ft_map_validation(char **map)
{
	int	size;

	size = ft_map_size(map);
	ft_border(map, size);
	ft_map_close(map, size, ' ');
	ft_map_close(map, size, 0);
	return (ft_check_plr(map, size));
}
