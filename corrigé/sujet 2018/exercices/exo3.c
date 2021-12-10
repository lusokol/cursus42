#include <stdio.h>
#include <string.h>

typedef struct Scoot
{
    char    modele[20];
    int     id;
    float   km;
    int     etat;
}   t_scoot;

#define TAILLE 100


// Question 3.1

void    menu()
{
    printf("1 : Louer un scooter\n");
    printf("2 : Retour d'un scooter\n");
    printf("3 : Etat d'un scooter\n");
    printf("4 ; Etat du parc de scooter\n");
    printf("0 : Fin du programme\n");
}

// Question 3.2

void AfficheEtat(t_scoot TabS[], int d)
{
    int i = 0;
    while (i < TAILLE && TabS[i].id != d)
        i++;
    if (i == TAILLE)
        return ;
    printf("Modele : %s\n", TabS[i].modele);
    printf("Numero d'identification : %d\n", TabS[i].id);
    printf("Kilometrage : %.1f\n", TabS[i].km);// %f fonctionne aussi mais %.1f permet d'afficher 1 seul chiffre apres la virgule
    printf("Etat : %d\n", TabS[i].etat);
}

// Question 3.3

int EstEnParc(t_scoot TabS[], int d)
{
    int i = 0;
    while (i < TAILLE && TabS[i].id != d)
        i++;
    if (i == TAILLE)
        return 0;
    return 1;
}

// Question 3.4
// /!\ QUESTION PAS CLAIRE, D'OU SORT LE KILOMETRAGE A AJOUTER AU SCOOTER ?
// JE NE SUIS PAS SUR D'AVOIR COMPRIS, J'AI MIS UN SCANF

void RetourScoot (t_scoot TabS[], int d)
{
    int     i = 0;
    float   km;
    while (i < TAILLE && TabS[i].id != d)
        i++;
    if (i == TAILLE || TabS[i].etat == 0)
        return ;
    scanf("Nombre de km.s effectué.s : %f\n", &km);
    TabS[i].km = km;
    TabS[i].etat = 0;
}

// Question 3.5

void AfficheEtatParc(t_scoot TabS[])
{
    int i = 0;
    int count = 0;
    float km = 0;
    while (i < TAILLE)
    {
        if (TabS[i].id)
            count++;
        i++;
    }
    printf("Il y a %d scooter(s) dans le parc\n", count);
    printf("Voici les differents id des scooter du parc :\n");
    i = 0;
    while (i < TAILLE)
    {
        if (TabS[i].id)
        {
            printf("id : '%d'\n", TabS[i].id);
            km += TabS[i].km;
        }
        i++;
    }
    printf("Kilometrage moyen : %.2f\n", (km / count));
}

// Question 3.6

void ElimineDoublons(t_scoot TabS[])
{
    int i = 0;
    int j;
    while (i < TAILLE - 1)
    {
        j = i + 1;
        while (j < TAILLE)
        {
            if (TabS[i].id == TabS[j].id)
                if (strcmp(TabS[i].modele, TabS[j].modele) == 0)
                {
                    TabS[j].id = 0;
                    TabS[j].modele[0] = '\0';
                    TabS[j].km = 0;
                    TabS[j].etat = 0;
                }
            j++;
        }
        i++;
    }
}

//////////////////////////////////////////// Pas dans les questions
void add_modele(t_scoot TabS[], char *str)
{
    int j = 0;
    while (str[j])
    {
        TabS[0].modele[j] = str[j];
        j++;
    }
    TabS[0].modele[j] = '\0';
}

void init_tab(t_scoot TabS[])
{
    int i = 0;
    while (i < TAILLE)
    {
        TabS[i].id = 0;
        TabS[i].modele[0] = '\0';
        TabS[i].km = 0;
        TabS[i].etat = 0;
        i++;
    }
}
////////////////////////////////////////////

// Question 3.7
// J'ai mis des printf en plus pour la lisibilité

int main()
{
    t_scoot TabS[TAILLE];
    init_tab(TabS);
    add_modele(TabS, "Yanaha");
    TabS[0].id = 11;
    TabS[0].km = 120;
    TabS[0].etat = 1;
    add_modele(TabS + 1, "Honda");
    TabS[1].id = 15;
    TabS[1].km = 30;
    TabS[1].etat = 0;
    add_modele(TabS + 2, "Suzuki");
    TabS[2].id = 3;
    TabS[2].km = 0;
    TabS[2].etat = 0;
    
    add_modele(TabS + 3, "Honda");//pour les tests de suppression des doublons
    TabS[3].id = 15;
    TabS[3].km = 30;
    TabS[3].etat = 0;

    // retourne un scooter avec un id de 15
    RetourScoot(TabS, 15);
    //affiche l'etat du parc
    printf("\n");
    AfficheEtatParc(TabS);
    //Check si le scooter avec un id de 2 existe
    printf("\n");
    int id = 2;
    printf("Le scooter avec l'ID %d ", id);
    if (EstEnParc(TabS, id))
        printf("existe.\n");
    else
        printf("n'existe pas.\n");
    // check l'etat du scooter pour un id de 11
    printf("\n");
    AfficheEtat(TabS, 11);
    // elimine les doublons
    printf("\nAvant la suppression des doublons :");
    AfficheEtatParc(TabS);
    ElimineDoublons(TabS);
    printf("Apres la suppression des doublons :");
    AfficheEtatParc(TabS);
}