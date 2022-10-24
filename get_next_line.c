#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	size;
	size_t	i;
	size_t	j;

	size = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	c = malloc(sizeof(char) * size + 1);
	if (!c)
		return (0);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen((char *)s2))
	{
		c[i] = s2[j];
		i++;
		j++;
	}
	c[i] = '\0';
	return (c);
}

static char *ft_read_line(char *l)
{
    int size;
    char *s;

    size = 0;
    if (!l[0])
        return (NULL);
    while (l[size] && l[size] != '\n')
        size++;
    s = (char *)malloc(sizeof(char) * (size + 2));
    if (!s)
        return (NULL);
    size = 0;
    while (l[size] && l[size] != '\n')
    {
        s[size] = l[size];
        size++;
    }
    if (l[size] == '\n')
    {
        s[size] = l[size];
        size++;
    }
    s[size] = '\0';
    return (s);
}

static void ft_read_buffer(int fd, t_list *stash)
{
    char *buff;
    char *s;
    int bytes_readed;

    buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buff)
        return ;
    bytes_readed = 1;
    while (!ft_strchr(ft_lstlast(&stash[0])->content, '\n') && bytes_readed != 0)
    {
        bytes_readed = read(fd, buff, BUFFER_SIZE);
        if (bytes_readed == -1)
        {
            free(buff);
            return ;
        }
        buff[bytes_readed] = '\0';
        s = ft_lstlast(&stash[0])->content;
        ft_lstadd_back(&stash, ft_lstnew(ft_strjoin(s, buff)));
    }
    free(buff);
}

static void ft_save_stash(t_list *stash)
{
    int size;
    int i;
    char *s;
    char *l;

    l = ft_lstlast(&stash[0])->content;
    size = 0;
    while (l[size] && l[size] != '\n')
        size++;
    if (!l[size])
        free(l);
    s = (char *)malloc(sizeof(char) * (ft_strlen(l) - size + 1));
    if (!s)
        return ;
    size++;
    i = 0;
    while (l[size])
        s[i++] = l[size++];
    s[i] = '\0';
    free(l);
    ft_lstadd_back(&stash, ft_lstnew(s));
}

char *get_next_line(int fd)
{
    char *line;
    char *last_read;
    static t_list *next_line;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (0);
    ft_read_buffer(fd, &next_line[0]);
    if (!ft_lstlast(&next_line[0])->content) //?
        return (NULL);
    last_read = ft_lstlast(&next_line[0])->content;
    line = ft_read_line(last_read);
    ft_save_stash(&next_line[0]);

    return (line);
}
/*
int main()
{
    int fd;
    int i;
	char *str;
    char s[10];

    fd = open("/Users/adiaz-uf/42cursus/get_next_line/archivo1", O_RDONLY);
    i = read(fd, s, 5);
    printf("%i", i);
    while(1)
    {
        str = get_next_line(fd);
        if (str == NULL)
            break;
        printf("%s", str);
        free(str);
    }
}*/