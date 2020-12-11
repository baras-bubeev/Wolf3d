/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:17:23 by mpowder           #+#    #+#             */
/*   Updated: 2020/11/21 02:55:37 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	if (dstsize != 0)
	{
		i = 0;
		while (src[i] && i < dstsize - 1)
			*dst++ = src[i++];
		*dst = '\0';
	}
	return (ft_strlen(src));
}
