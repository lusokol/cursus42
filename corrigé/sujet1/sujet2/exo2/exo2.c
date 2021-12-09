// si tu veux la tester, remplace le 4 du define par la taille de la matrice ('m' dans l'ennoncé)

#define SIZE 4

int sommeDiag(int mat[SIZE][SIZE])
{
    int resultat = 0;
    int index = 0;

    while (index < SIZE)
    {
        resultat = resultat + mat[index][index];
        index++;
    }
    return (resultat);
}