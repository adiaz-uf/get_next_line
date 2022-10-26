#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 15
# endif


char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int	ft_find_pos(const char *s, int c);
void	*ft_calloc(size_t n, size_t size);

#endif