#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	while (av[++i])
		printf("av[%d] : '%s'\n", i, av[i]);
	return (0);
}