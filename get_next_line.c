#include "get_next_line.h"
#include <fcntl.h>

static char *check_buffer(char *buf, char *ln, t_list **nln, int bytes_buf)
{
    int newl_pos;
    char *vs;
    char *l;
    t_list *last_line;

    newl_pos = 0;
    l = malloc(sizeof(char) * (ft_strlen(ln) + (newl_pos - 0)));
    if (ft_find_pos(buf, '\n') != 0)
    {
        newl_pos = ft_find_pos(buf, '\n');
        vs = ft_substr(buf, newl_pos, bytes_buf - newl_pos);
        last_line = ft_lstnew(vs);
        ft_lstadd_back(nln, last_line);
        l = ft_strjoin(ln, ft_substr(buf, 0, newl_pos));
    }
    else
        l = ft_strjoin(ln, ft_substr(buf, 0, newl_pos));
    free(ln);
    return (l);
}

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    static t_list **next_line;
    int bytes_readed;

    line = NULL;
    next_line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (0);
    bytes_readed = 1;
    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    bytes_readed = read(fd, buffer, BUFFER_SIZE);
    while (bytes_readed >= 0)
    {
        line = check_buffer(buffer, line, next_line, bytes_readed);
    }
    return(line);
}

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
}
