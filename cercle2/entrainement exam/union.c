#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int main(int ac, char **av)
{
	int tab[500];
	int k = 0;
	while (tab[k])
			tab[k++] = 0;
	if (ac != 3)
	{
		ft_putchar('\n');
		return 0;
	}
	int i;
	int j = 1;
	while (j < 3)
	{
		i = 0;
		while (av[j][i])
		{
			if (tab[av[j][i]] == 0)
			{
				ft_putchar(av[j][i]);
				tab[av[j][i]] = 1;
			}
			i++;
		}
		j++;
	}
	return (0);
}
