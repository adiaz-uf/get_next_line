#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*sub;

	i = ft_strlen(s);
	if (i - start < len)
		len = i - start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub || !s)
		return (0);
	j = 0;
	if (start < i)
	{
		while (j < len && s[j + start] != '\0')
		{
			sub[j] = s[j + start];
			j++;
		}
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	char	aux;
	char	*str;
	int		i;

	aux = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == aux)
			return (&str[i]);
		else
			i++;
	}
	if (aux == '\0')
		return (&str[i]);
	else
		return (0);
}

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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == 0)
		*lst = new;
	else
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
	}
}