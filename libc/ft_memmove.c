#include "libc.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	i = 0;
	p_dst = (char *)dst;
	p_src = (char *)src;
	if (!dst && !src)
		return (0);
	if (dst >= src && dst <= src + len)
	{
		while (--len)
			p_dst[len] = p_src[len];
		p_dst[len] = p_src[len];
	}
	else
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}
