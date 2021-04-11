#include "libc.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	i = ft_strlen(dst);
	dst_len = i;
	src_len = ft_strlen(src);
	if (dst_len < dstsize)
	{
		j = 0;
		while (src[j] && j < (dstsize - dst_len - 1))
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	return (src_len + dstsize);
}
