/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:45:08 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/14 01:59:06 by mpowder          ###   ########.fr       */
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

void		ft_map_validation(char **map)
{
	int	i;
	int	j;
	int	size;

	size = ft_map_size(map);
	printf("%d\n", size);
	while (i < size)
		printf("%s\n", map[i++]);
}
