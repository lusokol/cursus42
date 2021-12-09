#include <stdio.h>
#include <string.h>

//question 5.1

int hamming(char s1[], char s2[])
{
    if (strlen(s1) != strlen(s2))
        return (-1);
    int index = 0;
    int dif = 0;
    while (s1[index])
    {
        if (s1[index] != s2[index])
            dif++;
        index++;
    }
    return (dif);
}

// Question 5.2
// ATTENTON, ici je ne gere pas les erreures

void    suppression(char c, char S[])
{
    int size = strlen(S);
    int i = 0;
    int j = 1;
    char tmp;
    while (S[i] && S[j])
    {
        while (S[j] && S[i] != c)
        {
            j++;
            i++;
        }
        if (S[i] == c)
            while (S[j] == c)
                j++;
        if (S[i] == c && S[j] != c && j < size)
        {
            tmp = S[j];
            S[j] = S[i];
            S[i] = tmp;
            i++;
            j++;
        }
    }
    S[i] = '\0';
    printf("\'%s\'\n", S); //ici pour afficher, non demande dans l'exo
}

//Question 5.3

int cherche(char c, char S[])
{
    int i = 0;
    int count = 0;

    while (S && S[i])
    {
        if (S[i] == c)
            count++;
        i++;
    }
    return (count);
}

//Question 5.4

int cherche2(char c, char S[])
{
    int size = strlen(S);
    int index = 0;
    while (index < size)
    {
        if (S[index] == c)
            return (index);
        index++;
    }
    return (-1);
}

// Main

int main(int ac, char **av)
{
    if (ac != 3)
        return (0);
    printf("Hamming : \'%s\' et \'%s\' : %d\n", av[1], av[2], hamming(av[1], av[2]));
    printf("\'%s\' contient %d fois le caractere \'%c\'\n", av[2], cherche(av[1][0], av[2]), av[1][0]);
    printf("\nsupprime \'%c\' de \'%s\' : ", av[1][0], av[2]);
    suppression(av[1][0], av[2]);
    printf("\'d\' se trouve a l\'index %d de la string : %s\n", cherche2('d', av[2]), av[2]);   
    return (0);
}