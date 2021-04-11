#include "libc.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(size * count);
	if (p)
		ft_bzero(p, size * count);
	return (p);
}
