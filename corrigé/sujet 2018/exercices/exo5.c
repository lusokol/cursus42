#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

// Question 5.2

void    SupprimeNonAlphabetiquequi(char S[])
{
    int size = longueur(S);
    int i = 0;
    int j = 1;
    char tmp;
    while (S[i] && S[j] && j < size)
    {
        while (S[j] && isalpha(S[i]))
        {
            j++;
            i++;
        }
        if (!isalpha(S[i]))
            while (!isalpha(S[j]))
                j++;
        if (!isalpha(S[i]) && isalpha(S[j]) && j < size)
        {
            tmp = S[j];
            S[j] = S[i];
            S[i] = tmp;
            i++;
            j++;
        }
    }
    S[i] = '\0';
}

// Question 5.3
// Ici je fais la difference entre une lettre en majuscule et minuscule,
// attention a bien savoir ce qui est demandé

int frequenceLettre(char c, char chaine[])
{
    int count = 0;
    int i = 0;
    while (chaine[i] && i < longueur(chaine))
    {
        if (chaine[i] == c)
            count++;
        i++;
    }
    return (count);
}

int main()
{
    char str[] = "Salut ! Comment tu vas ? 123456789\0";

    int len = longueur(str);
    printf("\"%s\"===> %d caracteres\n", str, len);
    printf("Suppression des caracteres non alphabetique...\n");
    SupprimeNonAlphabetiquequi(str);
    printf("\"%s\"\n", str);
    printf("Cette chaine contient %d \'t\'\n", frequenceLettre('t', str));
    return (0);
}