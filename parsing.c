/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:42:54 by mpowder           #+#    #+#             */
/*   Updated: 2020/12/11 05:47:13 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_num(char **str, t_parse *prs, char c)
{
	int		i;
	int		max;
	int		num;

	i = 0;
	max = (c == 'R') ? 2 : 3;
	(*str)++;
	while (i < max)
	{
		num = 0;
		while (**str == ' ')
			(*str)++;
		while (ft_isdigit(**str))
		{
			num = num * 10 + (**str - '0');
			(*str)++;
		}
		(c == 'R') ? prs->r[i] = num : 0;
		(c == 'F') ? prs->f[i] = num : 0;
		(c == 'C') ? prs->c[i] = num : 0;
		(**str == ',') ? (*str)++ : 0;
		i++;
	}
}

static char	*ft_get_line(char **str)
{
	char	*s;
	int		len;
	int		i;

	(*str)++;
	if (**str != ' ')
		return (0);
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

int			ft_parsing(char *cfg)
{
	t_parse	prs;

	prs.s = 0;
	while (*cfg)
	{
		if ((*cfg == '\n' || *cfg == ' ') && cfg++)
			continue;
		(*cfg == 'R') ? ft_get_num(&cfg, &prs, *cfg) : 0;
		(*cfg == 'N' && *(++cfg) == 'O') ? prs.no = ft_get_line(&cfg) : 0;
		(*cfg == 'W' && *(++cfg) == 'E') ? prs.we = ft_get_line(&cfg) : 0;
		(*cfg == 'E' && *(++cfg) == 'A') ? prs.ea = ft_get_line(&cfg) : 0;
		(*cfg == 'S' && *(cfg + 1) == ' ') ? prs.s = ft_get_line(&cfg) : 0;
		(*cfg == 'S' && *(++cfg) == 'O') ? prs.so = ft_get_line(&cfg) : 0;
		(*cfg == 'F') ? ft_get_num(&cfg, &prs, *cfg) : 0;
		(*cfg == 'C') ? ft_get_num(&cfg, &prs, *cfg) : 0;
		cfg++;
	}
	printf("\n**************************\n");
	printf("x = |%d|\ny = |%d|\n", prs.r[0], prs.r[1]);
	printf("no = |%s|\n", prs.no);
	printf("so = |%s|\n", prs.so);
	printf("we = |%s|\n", prs.we);
	printf("ea = |%s|\n", prs.ea);
	printf(" s = |%s|\n", prs.s);
	printf("***F***\n");
	printf("R = |%3d|\nG = |%3d|\nB = |%3d|\n", prs.f[0], prs.f[1], prs.f[2]);
	printf("***C***\n");
	printf("R = |%3d|\nG = |%3d|\nB = |%3d|\n", prs.c[0], prs.c[1], prs.c[2]);
	return (1);
}
