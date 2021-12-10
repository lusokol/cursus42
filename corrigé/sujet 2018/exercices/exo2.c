// Question 2.1

// calcul la puissance de maniere iterative

#include <stdio.h>

int		puissance(int nb, int power)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

// calcul la puissance de maniere recursive (une autre maniere de proceder)

int     recursive_puissance(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * recursive_puissance(nb, power - 1));
}

// question 2.2
// si j'ai bien compris la formule, il faut calculer la somme de tous les
// chiffres compris dans l'intervale 'a..n' inclus

int Somme(int a, int n)
{
    int res = 0;

    while (a <= n)
    {
        res += a;
        a++;
    }
    return (res);
}

int main(void)
{
    printf("2 puissance 5 (iteratif): %d\n", puissance(2, 5));
    printf("2 puissance 5 (recursif): %d\n", recursive_puissance(2, 5));
    printf("somme de l'intervale 5..9 : %d\n", Somme(5, 9));
}