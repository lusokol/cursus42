#include "libft.h"
char    *recurs(int index, int *ret, int fd)
{
    char    buff[1];
    char    *str;
    int        test;
    test = read(fd, buff, 1); // on lit UN SEUL caractere
    if (test == 0) // si le read ne lit rien
        buff[0] = 0;
    if (buff[0] == '\n' || buff[0] == 0) //si le caractere actuel est 0 ou \n
    {
        if (!(str = malloc(sizeof(char) * index + 1)))
            return (0);
        str[index] = 0;
        *ret = 1;
        if (buff[0] == 0)
            *ret = 0;
        return (str);
    }
    else
    {
        if (!(str = recurs(index + 1, ret, fd)))
            return (0);
        str[index] = buff[0];
    }
    return (str);
}
int        get_next_line(int fd, char **line)
{
    int ret;
    ret = 1;
    *line = recurs(0, &ret, fd);
    return (ret);
}