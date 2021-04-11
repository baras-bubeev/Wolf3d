#include "libc.h"

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
