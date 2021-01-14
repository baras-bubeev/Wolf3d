/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:45:08 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/23 07:54:01 by mpowder          ###   ########.fr       */
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

static void	ft_border(char **map)
{
	int	i;
	// int	j;

	i = -1;
	while ((*map)[++i])
		if ((*map)[i] != ' ' && (*map)[i] != '1')
			ft_exit(1, MAP_ERROR);
	
}

void		ft_map_validation(char **map)
{
	// int	i;
	// int	j;
	int	size;

	size = ft_map_size(map);
	ft_border(map);
}
