#include <stdio.h>

// Question 6.1

// Affiche simplement '7'
// En mettant '&' tu vas a l'adresse
// et en mettant '*' et dereference l'adresse
// en gros le '&' annule le '*'

// Question 6.1

// Affiche '1 2 5'
// faire *(t + 2) = 5 revient a faire t[0 + 2] = 5

// Question 6.1
// dans le for on va afficher 2 valeurs (i < 2)
// les valeurs viennent de 'y' qui pointe sur (h + 2) donc y[0] = h[2], y[1] = h[3] etc..
// on afficher donc 3 et 4

// Question 6.2
// on nous donne des pointeur, on va donc assigner directement la 
// valeur a 'moy' par exemple en faisant '*moy = valeur'

void    stat(int *tab, int n, float *moy, int *min, int *max)
{
    int i = 0;

    *min = tab[0];
    *max = tab[0];
    while (i < n)
    {
        *moy += tab[i];
        if (tab[i] < *min)
            *min = tab[i];
        else if (tab[i] > *max)
            *max = tab[i];
        i++;
    }
    *moy /= n;
}

int main()
{
    int x;
    *(&x) = 7;
    printf("%d\n", x);

    printf("\n");

    int t[] = {1, 2, 3};
    *(t + 2) = 5;
    printf("%d %d %d\n", t[0], t[1], t[2]);

    printf("\n");

    int h[] = {1, 2, 3, 4, 5};
    int *y = h + 2;
    int i = 0;
    for (i = 0; i < 2; i++)
        printf("%d\n", y[i]);

    printf("\n");

    printf("notes/10 : 2 6 5 8 7 4 3 5 8 3\n");
    int tab[] = {2,6,5,8,7,4,3,5,8,3};
    float moyenne;
    int min;
    int max;
    stat(tab, 10, &moyenne, &min, &max);
    printf("Moyenne : %.2f\nNote min : %d\nNote max : %d\n", moyenne, min, max);
}