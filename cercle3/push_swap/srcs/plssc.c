#include <stdio.h>
#include <stdlib.h>

typedef struct test
{
    int lm;
    int m;
    int *tab;
    int *S;
} t_test;

void fill_tab(int *tab, int n, int value)
{
    int i = 0;

    while (i < n)
        tab[i++] = value;
}

void rec(int *tab, int m, int *prec, t_test *test, int max)
{
    int *S = malloc(sizeof(int) * max);
    fill_tab(S, max, 0);
    int i = m;
    int j = 1;
    while (i != -1)
    {
        S[max - j] = i;
        i = prec[i];
        j++;
    }
    test->S = S;
}

void plssc(int *tab, t_test *test)
{

    int *L = malloc(sizeof(int) * 20);
    fill_tab(L, 20, 1);
    int *prec = malloc(sizeof(int) * 20);
    fill_tab(prec, 20, -1);
    test->m = 0;
    int max;
    for (int i = 1; i <= 19 - 1; i++)
    {
        max = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (tab[j] <= tab[i] && L[j] > max)
            {
                max = L[j];
                prec[i] = j;
            }   
        }
        L[i] = max + 1;
        if (L[i] > L[test->m])
            test->m = i;
    }
    test->lm = L[test->m];
    test->tab = prec;
}

int main(int ac, char **av)
{
    int tab[] = {6,1,9,5,13,3,11,7,15,2,10,6,14,4,12,8,16,3,10,0};
    t_test *test = malloc(sizeof(t_test));

    plssc(tab, test);
    rec(tab, test->m, test->tab, test, test->lm);
    int i = 0;
    while (test->S[i])
        printf("\'%d\' ", test->S[i++]);
    printf("\n");
    return (0);
}