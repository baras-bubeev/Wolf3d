#include "cub3d.h"

void	ft_exit(int n, char *str)
{
	if (n < 0)
		perror(str);
	else
		ft_putendl_fd(str, 1);
	exit(n);
}
