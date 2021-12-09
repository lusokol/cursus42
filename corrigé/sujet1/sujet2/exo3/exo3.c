#include <stdio.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Cet exercice ne peut pas se compiler, en faisant les modifications necessaire tu pourrais le compiler.
// Ici je ne les ai pas faites sinon ca aurait changé le resultat des exercices

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct PokemonSt
{
    char nom[50] ; //le nom du Pokémon
    int niveau ; //le niveau du Pokémon
    int PV; //le nombre de points de vie
    int PC; //points de combat : le nombre de points de vie retirés à l'adversaire lors d'une attaque
} pokemon;

// Question 3.1

void    printPokemon(pokemon p)
{
    printf("Nom du pokemon : %s\nniveau : %d\nPV : %d\nPC : %d\n", p.nom, p.niveau, p.PV, p.PC);
}

// Question 3.2

pokemon evolution(pokemon p)
{
    p.niveau += 1;
    p.PV += 20;
    p.PC += 10;
}

// Question 3.3

pokemon attaque(pokemon p1, pokemon p2)
{
    p2.PV -= p1.PC;
    if (p2.PV < 0)
        p2.PV = 0;
    // ca peut tenir en une seule ligne : 
    // p2.PV = (p2.PV <= p1.PC) ? 0 : p2.PV - p1.PC;
    // les pv du p2 valent (si la force du p1 est superieur au pv du p2) 0 sinon la difference;
}

// Question 3.4

#define MAX_POKEMON 9999

int nbPokemonVivants(pokemon tab[MAX_POKEMON], int N)
{
    int index = 0;
    int poke_vivant = 0;

    while (index < N && index < MAX_POKEMON)
    {
        if (tab[index].PV > 0)
            poke_vivant++;
        index++;
    }
    return (poke_vivant);
}

// Question 3.5

pokemon pirePokemon(pokemon tab[MAX_POKEMON], int N)
{
    int index = 0;
    pokemon pire_poke;

    pire_poke = tab[0];
    while (index < N && index < MAX_POKEMON)
    {
        if (pire_poke.PC > tab[index].PC)
            pire_poke = tab[index];
        index++;
    }
    return (pire_poke);
}

// Question 3.6
// (j'ai un doute sur cet exo, sur la maniere de supprimer le nom. Le sujet est quelque peu bizarre)


void supprimePirePokemon(pokemon tab[MAX_POKEMON], int *N)
{
    pokemon pire = pirePokemon(tab, *N);
    int index = 0;
    while (index < N[0])
    {
        if (strcmp(pire.nom, tab[index].nom) == 0 && pire.PC == tab[index].PC)
        {
            tab[index].PV = 0;
            tab[index].PC = 0;
            tab[index].niveau = 0;
            tab[index].nom[0] = '\0';//ici
            N[0]--;
            return ;
        }
        index++;
    }
}

// Question 3.7
// Leur main est bizarre, ca ne risque pas de fonctionner mais ils attendent ca :

int main(){
// déclaration et initialisation d’un tableau de Meubles
pokemon tab[MAX_POKEMON];
int N=3;
tab[0].nom[0] = 'P'; tab[0].niveau = 3;
tab[0].PV = 15; tab[0].PC = 26;
tab[1].nom[0] = 'M' ; tab[1].niveau = 1;
tab[1].PV = 8 ; tab[1].PC = 12;
tab[2].nom[0] = 'R' ; tab[2].niveau = 2;
tab[2].PV = 23; tab[2].PC = 5;
// Afficher le Pokémon Rondoudou
printf("rondoudou :\n"); // CETTE LIGNE NE FAIT PAS PARTIE DE LA REPONSE
printPokemon(tab[2]);

// Afficher tous les élément du tableau
printf("\nTous les elements :\n"); // CETTE LIGNE NE FAIT PAS PARTIE DE LA REPONSE
int index = 0;

while (index < N)
{
    printPokemon(tab[index]);
    index++;
}

// faîtes évoluer le Miaouss dans le tableau
evolution(tab[1]);

// simulez une attaque de Miaouss sur Pikachu


attaque(tab[1], tab[0]);

// affichez le nombre de Pokémons encore vivants

printf("\nnombre de pokemon vivant dans l\'equipe : %d\n", nbPokemonVivants(tab, N));

// supprimez le Pokémon la plus faible

supprimePirePokemon(tab, &N); // /!\ ne pas oublier l'esperluette '&'

return 0 ;
}