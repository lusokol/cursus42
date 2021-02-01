#include <unistd.h>

void ft_putchar(char a)
{
	write(1, &a, 1);
}

int check(char a, char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == a)
			return 1;
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{
	int tab[500];
	int k = 0;
	if (ac != 3)
	{
		ft_putchar('\n');
		return 0;
	}
	while (k < 500)
		tab[k++] = 0;
	int i = 0;
	while (av[1][i])
	{
		if (check(av[1][i], av[2]) && tab[av[1][i]] == 0)
		{
			ft_putchar(av[1][i]);
			tab[av[1][i]] = 1;
		}
		i++;
	}
	ft_putchar('\n');
	return 0;
}
