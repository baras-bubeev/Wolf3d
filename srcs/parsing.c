#include "cub3d.h"

static void	ft_get_num(char c, int *dst, char **s)
{
	int		i;
	int		max;

	i = 0;
	max = (c == 'R') ? 2 : 3;
	while (i < max)
	{
		(max == 2 && dst[i] != 0) ? ft_exit(1, NOT_VALID_FILE) : 0;
		(max == 3 && dst[i] != -1) ? ft_exit(1, NOT_VALID_FILE) : 0;
		while (**s == ' ')
			(*s)++;
		(!ft_isdigit(**s)) ? ft_exit(1, NOT_VALID_FILE) : 0;
		dst[i] = **s - '0';
		while (ft_isdigit(*(++(*s))))
			dst[i] = dst[i] * 10 + (**s - '0');
		(max == 3 && **s == ',') ? (*s)++ : 0;
		(max == 2 && dst[i] <= 0) ? ft_exit(1, NOT_VALID_FILE) : 0;
		(max == 3 && (dst[i] < 0 || dst[i] > 255)) ?
			ft_exit(1, NOT_VALID_FILE) : 0;
		i++;
	}
	while (**s == ' ')
		(*s)++;
}

static void	ft_get_line(char **s, char **dst)
{
	int		len;
	int		i;

	(*dst) ? ft_exit(1, NOT_VALID_FILE) : 0;
	(*s)++;
	(**s != ' ') ? ft_exit(1, NOT_VALID_FILE) : 0;
	while (**s == ' ')
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != '\n' && (*s)[len] != ' ')
		len++;
	(!(*dst = (char *)malloc(sizeof(*dst) * (len + 1)))) ?
		ft_exit(-1, MALLOC_ERROR) : 0;
	i = 0;
	while (i < len)
	{
		(*dst)[i++] = **s;
		(*s)++;
	}
	(*dst)[i] = 0;
	while (**s == ' ')
		(*s)++;
}

static char	*ft_get_config(char *s, t_parse *cfg)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*s && i < 8)
	{
		while (*s == '\n' || *s == ' ')
			s++;
		tmp = s;
		(*s == 'N' && *(s + 1) == 'O' && s++) ? ft_get_line(&s, &cfg->no) : 0;
		(*s == 'W' && *(s + 1) == 'E' && s++) ? ft_get_line(&s, &cfg->we) : 0;
		(*s == 'E' && *(s + 1) == 'A' && s++) ? ft_get_line(&s, &cfg->ea) : 0;
		(*s == 'S' && *(s + 1) == 'O' && s++) ? ft_get_line(&s, &cfg->so) : 0;
		(*s == 'S' && *(s + 1) == ' ') ? ft_get_line(&s, &cfg->s) : 0;
		(*s == 'R' && *(s + 1) == ' ') ? ft_get_num(*s++, cfg->r, &s) : 0;
		(*s == 'F' && *(s + 1) == ' ') ? ft_get_num(*s++, cfg->f, &s) : 0;
		(*s == 'C' && *(s + 1) == ' ') ? ft_get_num(*s++, cfg->c, &s) : 0;
		(tmp == s) ? ft_exit(1, NOT_VALID_FILE) : 0;
		i++;
	}
	while (*s && *s == '\n')
		s++;
	(ft_strnstr(s, "\n\n", ft_strlen(s))) ? ft_exit(1, NOT_VALID_FILE) : 0;
	return (s);
}

void		ft_parsing(char *str, t_parse *cfg)
{
	cfg->r[0] = 0;
	cfg->r[1] = 0;
	cfg->no = 0;
	cfg->so = 0;
	cfg->we = 0;
	cfg->ea = 0;
	cfg->s = 0;
	cfg->f[0] = -1;
	cfg->f[1] = -1;
	cfg->f[2] = -1;
	cfg->c[0] = -1;
	cfg->c[1] = -1;
	cfg->c[2] = -1;
	if (!(cfg->map = ft_split(ft_get_config(str, cfg), '\n')))
		ft_exit(-1, MALLOC_ERROR);
}
