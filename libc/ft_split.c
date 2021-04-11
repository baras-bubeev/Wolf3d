#include "libc.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	if (ft_strlen(s) > 0)
	{
		while (s[i])
		{
			if (s[i] != c && s[i - 1] == c)
				count++;
			i++;
		}
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char	*ft_getword(char const **s, char c)
{
	char	*p;
	int		wlen;
	int		i;

	wlen = ft_wordlen(*s, c);
	if (!(p = (char *)malloc(sizeof(p) * (wlen + 1))))
		return (0);
	i = 0;
	while (i < wlen)
	{
		p[i++] = **s;
		(*s)++;
	}
	p[i] = '\0';
	return (p);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	int		wcount;
	int		i;

	if (!s)
		return (0);
	wcount = ft_count_word(s, c);
	if (!(strs = (char **)malloc(sizeof(strs) * (wcount + 1))))
		return (0);
	i = 0;
	while (i < wcount)
	{
		while (*s == c)
			s++;
		if (!(strs[i++] = ft_getword(&s, c)))
		{
			while (--i >= 0)
				free(strs[i]);
			free(strs);
			return (0);
		}
	}
	strs[i] = 0;
	return (strs);
}
