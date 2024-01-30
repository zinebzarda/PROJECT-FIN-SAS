#include <stdio.h>
#include <string.h>

struct Date
{
    int jour;
    int mois;
    int annee;
};

typedef struct
{
    char nom[50];
    char dsc[300];
    char priorite[20];
    struct Date dateEcheance;
} Tache;
Tache t;
int numTache = 0;
Tache listTache[300];

// ################ Ajouter #################
void Ajouter_tache()
{
    // le nom de tache
    printf("Ajouter:\n ");
    printf("Entrez le titre de tache : ");
    scanf(" %[^\n]s", listTache[numTache].nom);
    // la description
    printf("Entrez la description de la tache : ");
    scanf(" %[^\n]s", listTache[numTache].dsc);
    // priorite
    printf("entrer la priorite de la tache : ");
    scanf(" %[^\n]s", listTache[numTache].priorite);
    // la date
    printf("entrer la date d' echeance :\n");
    printf("Jour: (entre 1 et 31) ");
    scanf("%2d", &listTache[numTache].dateEcheance.jour);
    // Virifie si le jour entre 1 et 31
    if (listTache[numTache].dateEcheance.jour < 1 || listTache[numTache].dateEcheance.jour > 31)
    {
        printf("Jour invalid. Entrer un jour entre 1 et 31.\n");
        return;
    }
    printf("Mois: (entre 1 et 12) ");
    scanf("%2d", &listTache[numTache].dateEcheance.mois);
    // Virifie si le mois entre 1 et 12
    if (listTache[numTache].dateEcheance.mois < 1 || listTache[numTache].dateEcheance.mois > 12)
    {
        printf("Mois invalid. Entrer un mois entre 1 et 12.\n");
        return;
    }
    printf("Annee: (entre 2023 et 2024) ");
    scanf("%4d", &listTache[numTache].dateEcheance.annee);
    // Virifie si l'annee entre  2023 et 2024
    if (listTache[numTache].dateEcheance.annee < 2023 || listTache[numTache].dateEcheance.annee > 2024)
    {
        printf("Annee invelid. Entrer annee entre 2023 et 2024.\n");
        return;
    }

    numTache++;
    printf(" la tache ajoutee avec succes.\n");
}

// ################ Afficher #################
void Affichage_tache()
{
   if (numTache == 0)
   {
       printf("vide!!!\n");
   }
    printf("Les taches :\n");
    for (int i = 0; i < numTache; i++)
    {
        printf("Titre de tache: %s \nDescription de tache: %s \nPriorite de tache: %s \nLa date d'echeance est: %d/%d/%d\n",
               listTache[i].nom,
               listTache[i].dsc,
               listTache[i].priorite,
               listTache[i].dateEcheance.jour,
               listTache[i].dateEcheance.mois,
               listTache[i].dateEcheance.annee);
    }
}