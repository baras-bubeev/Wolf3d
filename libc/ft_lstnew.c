#include "libc.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = malloc(sizeof(p));
	if (!p)
		return (0);
	p->content = content;
	p->next = NULL;
	return (p);
}
