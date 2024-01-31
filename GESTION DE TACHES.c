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

//  ################ Modifier #################
void Modifier_tache()
{
    char nv_nom[50];

    printf("Entrer le Titre de la tache a modifier : ");
    scanf(" %[^\n]s", nv_nom);

    int i;
    for (i = 0; i < numTache; i++)
    {
        if (strcmp(listTache[i].nom, nv_nom) == 0)
        {
            printf("Nouveau titre est :");
            scanf(" %[^\n]s", listTache[i].nom);
            printf("Nouvelle description est :");
            scanf(" %[^\n]s", listTache[i].dsc);
            printf("Nouvelle priorite est :");
            scanf(" %[^\n]s", listTache[i].priorite);
            printf("entrer la date d' echeance :\n");
            // scanf("%d/%d/%d", &listTache[numTache].dateEcheance.jour,
            //       &listTache[numTache].dateEcheance.mois,
            //       &listTache[numTache].dateEcheance.annee);

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
            printf("Tache de titre %s modifiee avec succes.\n", nv_nom);
            break;
        }
    }
}

//  ################ Supprimer #################
void Supprimer_tache()
{
    char nv_nom[50];
    printf("Entrer le titre de la tache a supprimer : ");
    scanf(" %[^\n]s", nv_nom);

    int i;
    for (i = 0; i < numTache; i++)
    {
        if (strcmp(listTache[i].nom, nv_nom) == 0)
        {
            for (int j = i; j < numTache - 1; j++)
            {
                strcpy(listTache[j].nom, listTache[j + 1].nom);
            }
            numTache--;
            printf("Tache de titre %s supprimee avec succes.\n", nv_nom);
            break;
        }
    }

    if (i == numTache)
        printf("Tache de titre %s non trouvee.\n", nv_nom);
}

//  ################ Ordonner #################

void OrdonnerDate()
{
    Tache temp;
    for (int i = 0; i < numTache - 1; i++)
    {
        for (int j = i + 1; j < numTache; j++)
        {
            if (listTache[i].dateEcheance.annee > listTache[j].dateEcheance.annee ||
                (listTache[i].dateEcheance.annee == listTache[j].dateEcheance.annee && listTache[i].dateEcheance.mois > listTache[j].dateEcheance.mois) ||
                (listTache[i].dateEcheance.annee == listTache[j].dateEcheance.annee && listTache[i].dateEcheance.mois == listTache[j].dateEcheance.mois && listTache[i].dateEcheance.jour > listTache[j].dateEcheance.jour))
            {

                temp = listTache[i];
                listTache[i] = listTache[j];
                listTache[j] = temp;
            }
        }
    }
    printf("Les tache a ete trie par Date d'echeance.\n ");
}
//  ################ Filtrer par prioriter #################

void FiltrerParPrioriter()
{
    char nv_prioriter[50];

    printf("Entrer le prioriter de la tache :\n ");
    scanf(" %[^\n]s", nv_prioriter);

    ;
    for (int i = 0; i < numTache; i++)
    {
        if (strcmp(listTache[i].priorite, nv_prioriter) == 0)
        {
            printf("Titre de tache: %s || Description de tache: %s ||  Priorite de tache: %s ||  La date d'echeance est: %d/%d/%d\n",
                   listTache[i].nom,
                   listTache[i].dsc,
                   listTache[i].priorite,
                   listTache[i].dateEcheance.jour,
                   listTache[i].dateEcheance.mois,
                   listTache[i].dateEcheance.annee);
        }
    }
}

//  ################ Filtrer par Date #################
void FiltrerParDate()
{
    int nv_jour, nv_mois, nv_annee;
    printf("Jour: (entre 1 et 31) ");
    scanf("%2d", &nv_jour);
    // Virifie si le jour entre 1 et 31
    if (nv_jour < 1 || nv_jour > 31)
    {
        printf("Jour invalid. Entrer un jour entre 1 et 31.\n");
        return;
    }
    printf("Mois: (entre 1 et 12) ");
    scanf("%2d", &nv_mois);
    // Virifie si le mois entre 1 et 12
    if (nv_mois < 1 || nv_mois > 12)
    {
        printf("Mois invalid. Entrer un mois entre 1 et 12.\n");
        return;
    }
    printf("Annee: (entre 2023 et 2024) ");
    scanf("%4d", &nv_annee);
    // Virifie si l'annee entre  2023 et 2024
    if (nv_annee < 2023 || nv_annee > 2024)
    {
        printf("Annee invelid. Entrer annee entre 2023 et 2024.\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < numTache; i++)
    {
        if (listTache[i].dateEcheance.jour == nv_jour && listTache[i].dateEcheance.mois == nv_mois && listTache[i].dateEcheance.annee == nv_annee)
        {
            printf("Titre de tache: %s || Description de tache: %s ||  Priorite de tache: %s ||  La date d'echeance est: %d/%d/%d\n",
                   listTache[i].nom,
                   listTache[i].dsc,
                   listTache[i].priorite,
                   listTache[i].dateEcheance.jour,
                   listTache[i].dateEcheance.mois,
                   listTache[i].dateEcheance.annee);
        }
    }
}

//  ################ Menu #################
void menu()
{
    int choix;
    while (choix != 8)
    {
       printf("|------------------------- MENU ----------------------------|\n"
               "| \033[92m           1 : Ajouter une tache                       \033[0m   |\n"
               "| \033[92m           2 : Afficher la tache                       \033[0m   |\n"
               "| \033[92m           3 : Modifier la tache                       \033[0m   |\n"
               "| \033[91m           4 : Supprimer la tache                      \033[0m   |\n"
               "| \033[92m           5 : Ordonner la tache par date              \033[0m   |\n"
               "| \033[92m           6 : Filtrer la tache par prioriter          \033[0m   |\n"
               "| \033[92m           7 : Filtrer la tache par date               \033[0m   |\n"
               "| \033[91m           8 : quitter                                 \033[0m   |\n"
               "|               votre choix SVP [1-8] :                     |\n"
               "|_____________________|\n");

        printf("\n-->> : ");
        scanf("%d", &choix);
        printf("  *************\n");
        if (choix == 0)
            choix = 8;

        switch (choix)
        {
        case 1:
            Ajouter_tache();
            break;
        case 2:
            Affichage_tache();
            break;
        case 3:
            Modifier_tache();
            break;
        case 4:
            Supprimer_tache();
            break;
        case 5:
            OrdonnerDate();
            break;
        case 6:
            FiltrerParPrioriter();
            break;
        case 7:
            FiltrerParDate();
            break;
        case 8:
            printf("Au revoir\n");
            break;
        default:
            printf("Entree invalide !! entre [1-8] svp\n");
        }
    }
}

int main()
{
    menu();

    return 0;
}
