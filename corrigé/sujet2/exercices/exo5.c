#include <stdio.h>

// Question 5.1

int longueur(char chaine[])
{
    int i = 0;
    if (!chaine) // si j'ai pas de string, je retourne 0, c'est une protection
        return (0);
    while (chaine[i])
        i++;
    return (i);
}

// Question 2

void SupprimeNonAlphabetiquequi(char chaine[])
{
    int		ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122))
			return (0);
		i++;
	}
	return (1);
}
}

int main()
{
    char str[] = "Salut ! Comment tu vas ?";

    int len = longueur(str);
    printf("\'%s\'===> %d caracteres\n", str, len);
    return (0);
}