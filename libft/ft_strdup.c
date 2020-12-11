/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:26:51 by mpowder           #+#    #+#             */
/*   Updated: 2020/11/21 02:39:47 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*p;

	i = 0;
	size = ft_strlen(s1);
	if (!(p = malloc(size + 1)))
		return (0);
	while (i < size)
		p[i++] = *s1++;
	p[i] = '\0';
	return (p);
}
