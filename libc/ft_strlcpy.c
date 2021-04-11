#include "libc.h"

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
