/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:42:54 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/11 04:34:27 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_get_line(char **str)
{
	char	*s;
	int		len;
	int		i;

	while (**str == ' ')
		(*str)++;
	len = 0;
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	if (!(s = (char *)malloc(sizeof(s) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		s[i++] = **str;
		(*str)++;
	}
	s[i] = 0;
	return (s);
}

static int	ft_resolution(char **str, t_parse *prs)
{
	(*str)++;
	if (**str != ' ')
		return (0);
	if ((prs->r[0] = ft_atoi(*str)) <= 0)
		return (0);
	while (**str == ' ')
		(*str)++;
	while (ft_isdigit(**str))
		(*str)++;
	if ((prs->r[1] = ft_atoi(*str)) <= 0)
		return (0);
	while (**str != '\n')
	{
		if (**str != ' ')
			return (0);
		(*str)++;
	}
	return (1);
}

static int	ft_orient(char **str, t_parse *prs)
{
	if (**str == 'S' && (*str)++)
	{
		if (**str == 'O' && (*str)++ && **str == ' ')
		{
			prs->so = ft_get_line(str);
			return (1);
		}
		else if (**str == ' ')
		{
			prs->s = ft_get_line(str);
			return (1);
		}
		else
			return (0);
	}
	if (**str == 'N' && (*str)++)
		if (**str == 'O' && (*str)++ && **str == ' ')
			prs->no = ft_get_line(str);
		else
			return (0);
	if (**str == 'W' && (*str)++)
		if (**str == 'E' && (*str)++ && **str == ' ')
			prs->we = ft_get_line(str);
		else
			return (0);
	if (**str == 'E' && (*str)++)
		if (**str == 'A' && (*str)++ && **str == ' ')
			prs->ea = ft_get_line(str);
		else
			return (0);
	return (1);
}

int		ft_parsing(char *cfg)
{
	t_parse	prs;

	prs.s = 0;
	while (*cfg)
	{
		if ((*cfg == '\n' || *cfg == ' ') && cfg++)
			continue ;
		if (*cfg == 'R')
			if (!ft_resolution(&cfg, &prs))
				return (-1);
		if (*cfg == 'N' || *cfg == 'S' || *cfg == 'W' || *cfg == 'E')
			if (!ft_orient(&cfg, &prs))
				return (-1);
		if (*cfg == 'F' && cfg++)
		{
			prs.f[0] = ft_get_num(&cfg);
			prs.f[1] = ft_get_num(&cfg);
			prs.f[2] = ft_get_num(&cfg);
		}
		if (*cfg == 'C' && cfg++)
		{
			prs.c[0] = ft_get_num(&cfg);
			prs.c[1] = ft_get_num(&cfg);
			prs.c[2] = ft_get_num(&cfg);
		}
		cfg++;
	}
	printf("\n**************************\n");
	printf("x = |%d|\ny = |%d|\n", prs.r[0], prs.r[1]);
	printf("no = |%s|\n", prs.no);
	printf("so = |%s|\n", prs.so);
	printf("we = |%s|\n", prs.we);
	printf("ea = |%s|\n", prs.ea);
	// printf(" s = |%s|\n", prs.s);
	printf("***F***\n");
	printf("R = |%3d|\nG = |%3d|\nB = |%3d|\n", prs.f[0], prs.f[1], prs.f[2]);
	printf("***C***\n");
	printf("R = |%3d|\nG = |%3d|\nB = |%3d|\n", prs.c[0], prs.c[1], prs.c[2]);
	return (1);
}