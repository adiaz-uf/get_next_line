#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnodo;

	newnodo = (t_list *)malloc(sizeof(t_list));
	if (!newnodo)
		return (0);
	newnodo->content = content;
	newnodo->next = 0;
	return (newnodo);
}