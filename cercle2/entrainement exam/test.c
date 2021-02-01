#include "../../cercle1/libft/libft.h"
#include <stdio.h>

static int        is_separator(char c, char sep)
{
    if (c == sep)
        return (1);
    return (0);
}

static int        count_word(const char *s, char sep)
{
    int i;
    int    count;

    count = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (!is_separator(s[i], sep) && (!i || is_separator(s[i - 1], sep)))
            count++;
        else if (!is_separator(s[i], sep) && i == 0)
            count++;
        i++;
    }
    return (count);
}

static void        ft_free_array(char **array)
{
    int i;

    i = -1;
    while (array && array[++i])
        free(array[i]);
    if (array)
        free(array);
}

static char        **ft_malloc(char **array, const char *s, char sep)
{
    int i;
    int size;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        while (s[i] && is_separator(s[i], sep))
            i++;
        size = 0;
        while (s[i] && !is_separator(s[i], sep))
        {
            size++;
            i++;
        }
        array[j] = (char *)malloc(sizeof(char) * (size + 1));
        if (array[j] == NULL)
            return (NULL);
        ft_strlcpy(array[j], (char *)(s + i - size), size + 1);
        array[j++][size] = '\0';
    }
    return (array);
}

char            **ft_split(char const *s, char c)
{
    char    **array;
    int        size;
    int        j;

    size = count_word(s, c);
    j = 0;
    array = (char **)malloc(sizeof(char *) * (size + 1));
    if (array == NULL)
        return (NULL);
    array = ft_malloc(array, s, c);
    if (array == NULL)
    {
        ft_free_array(array);
        return (NULL);
    }
    array[size] = NULL;
    return (array);
}

int main(int ac, char **av)
{
    char **tab;

    tab = ft_split(av[1], av[2][0]);
    int i = 0;
    while (tab[i])
    {
        printf("str : '%s'\n", tab[i++]);
    }
    system("leaks a.out");
    return (0);
}