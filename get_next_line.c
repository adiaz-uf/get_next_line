#include "get_next_line.h"
#include <fcntl.h>

static char *ft_read_line(char *stash)
{
    int size;
    char *s;

    size = 0;
    if (!stash[size])
        return (0);
    while (stash[size] && stash[size] != '\n')
        size++;
    s = (char *)malloc(sizeof(char) * (size + 2));
    if (!s)
        return (0);
    size = 0;
    while (stash[size] && stash[size] != '\n')
    {
        s[size] = stash[size];
        size++;
    }
    if (stash[size] == '\n')
        s[size] = '\n';
    else
        s[size] = '\0';
    s[size + 1] = '\0';
    return (s);
}

static char *ft_save_stash(char *stash)
{
    int size;
    int i;
    char *s;

    size = 0;
    while (stash[size] && stash[size] != '\n')
        size++;
    if (!stash[size])
    {
        free(stash);
        return (0);
    }
    s = (char *)malloc(sizeof(char) * (ft_strlen(stash) - size + 1));
    if (!s)
        return (0);
    size++;
    i = 0;
    while (stash[size])
        s[i++] = stash[size++];
    s[i] = '\0';
    free(stash);
    return (s);
}

static char *ft_read_buffer(int fd, char *stash)
{
    char *buff;
    int bytes_readed;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (0);

    bytes_readed = 1;
    while (!ft_strchr(stash, '\n') && bytes_readed != 0)
    {
        bytes_readed = read(fd, buff, BUFFER_SIZE);
        if (bytes_readed == -1)
        {
            free(buff);
            return (0);
        }
        buff[bytes_readed] = '\0';
        stash = ft_strjoin(stash, buff); 
    }
    free(buff);  
    return (stash);
}

char *get_next_line(int fd)
{
    char *line;
    static char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (0);
    next_line = ft_read_buffer(fd, next_line);
    if (!next_line) 
        return (0);
    line = ft_read_line(next_line);
    next_line = ft_save_stash(next_line);
    return (line);
}
/*
int main()
{
    int fd;
	char *str;
   
    fd = open("/Users/adiaz-uf/42cursus/get_next_line/archivo1", O_RDONLY);

    while(1)
    {
        str = get_next_line(fd);
        if (!str)
            break;
        printf("%s", str);
        free(str);
    }
}*/
