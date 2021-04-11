#include "libc.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!s)
		return (0);
	if (!(p = (char *)malloc(len + 1)))
		return (0);
	if (start >= ft_strlen(s))
	{
		*p = '\0';
		return (p);
	}
	while (i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
