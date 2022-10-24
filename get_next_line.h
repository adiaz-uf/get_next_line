#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

typedef struct s_list 
{
    char            *content;
    struct s_list   *next;
}   t_list;

char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int	ft_find_pos(const char *s, int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);

#endif