#include <stdio.h>

#define _M 5
#define _N 4

// Ici j'increment 'i' pour me deplacer dans le tableau non pas de 1 mais avec la variable 'increment'
// Cette variable vaut 1 et quand j'arrive au bout de la ligne je change le signe de cette derniere
// on passe d'une incrementation de 'i' de 1 a -1
// je descend juste d'une ligne a chaque fois

void accordeon(int Tab[_M][_N], int m, int n)
{
    int i = 0;
    int j = 0;
    int increment = 1;
    while (j < m)
    {
        printf("%d, ", Tab[j][i]);
        i += increment; // incrementation
        if (i == n || i == -1)
        {
            increment = -increment; // changement de signe
            i += increment;
            j++; // changement de ligne
        }
    }
    printf("\n");
}

int main()
{
    int tab[_M][_N] =  {{0, 1, 2, 3},
                        {4, 5, 6, 7},
                        {8, 9, 10,11},
                        {12,13,14,15},
                        {16,17,18,19}};
    printf("Doit afficher :\n0, 1, 2, 3, 7, 6, 5, 4, 8, 9, 10, 11, 15, 14, 13, 12, 16, 17, 18, 19\nAffiche : \n");
    accordeon(tab, _M, _N);
    return (0);
}