#include <stdio.h>
int mystere(int x, int y)
{
    int z, w;
    z = 0;
    w = x;
    while(w <= y)
    {
        z = z + w * w;
        w = w + 1;
    }
    return z;
}

int main()
{
    int i, j;
    printf("Entrer deux valeurs\n");
    scanf("%d %d", &i, &j);
    printf("le resultat de la fonction mystere est: %d\n", mystere(i,j));
    return 0;
}