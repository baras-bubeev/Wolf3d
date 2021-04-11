#include "libc.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*p;

	new = 0;
	while (lst)
	{
		p = ft_lstnew(f(lst->content));
		if (!p)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, p);
		lst = lst->next;
	}
	return (new);
}
