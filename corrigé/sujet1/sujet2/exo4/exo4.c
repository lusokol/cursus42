#include <stdio.h>

// Question 4.1

float moyenne(int notes[], int N)
{
    int i = 0;
    float resultat = 0;
    while (i < N)
    {
        resultat += notes[i];
        i++;
    }
    resultat = resultat / N;
    return (resultat);
}

// Question 4.2

float pourcentage(int notes[], int N)
{
    float sup = 0;
    int moy = moyenne(notes, N);
    float resultat;
    int index = 0;
    while (index < N)
    {
        if (notes[index] > moy)
            sup++;
        index++;
    }
    resultat = (sup / N) * 100;
    return (resultat);
}

// Question 4.3

int valide(int notes[], int N)
{
    int notes_valide = 0;
    int index = 0;
    while (index < N)
    {
        if (notes[index] > 10) // GROS DOUTE : consigne pas claire : "renvoie le nombre de notes SUPERIEUR à la moyenne  de validation (10)
            notes_valide++;    // la consigne dit "note > 10", la logique veut "note >= 10" : demande a tes profs
        index++;
    }
    return (notes_valide);
}

// MAIN

int main()
{
    int tab[6] = {8, 12, 15, 16, 7, 6};
    int N = 6;
    printf("moyenne : %.2f\n", moyenne(tab, N));
    printf("notes au dessus de la moyenne : %.1f%%\n", pourcentage(tab, N));
    printf("Notes valide : %d\n", valide(tab, N));
    return (0);
}