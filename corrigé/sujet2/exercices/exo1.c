#include <stdio.h>
int main()
{
    const int n = 10;
    int T[n];
    int i,j;

    for (i = 0; i < n; i++)
        T[i] = 0;

    T[1] = T[2] = 1;
    for (j = 0; j < 3; j++)
        for (i = 1; i < n; i++)
            T[i] = T[i] + T[i - 1];

    for (i = 0; i < n; i++)
        printf("%d ", T[i]);
    return 0;
}

// Le programme affiche : "0 1 4 9 16 25 36 49 64 81"
// il affiche les racines carrées des chiffres allant de 0 à 9