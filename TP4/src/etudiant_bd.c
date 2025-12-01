#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

#define NB_ETUDIANTS 5
#define TAILLE_NOM 64
#define TAILLE_PRENOM 64
#define TAILLE_ADRESSE 256

struct etudiant
{
    char nom[TAILLE_NOM];
    char prenom[TAILLE_PRENOM];
    char adresse[TAILLE_ADRESSE];
    int note1;
    int note2;
};

static void lire_ligne(char *buffer, size_t taille)
{
    if (fgets(buffer, (int)taille, stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
    }
}

int main(void)
{
    struct etudiant etudiants[NB_ETUDIANTS];
    char ligne[512];

    printf("=== Exercice 4.3 : Base de donnees etudiants ===\n");

    for (int i = 0; i < NB_ETUDIANTS; i++)
    {
        printf("\nEntrez les details de l'etudiant.e %d :\n", i + 1);

        printf("Nom : ");
        lire_ligne(etudiants[i].nom, sizeof(etudiants[i].nom));

        printf("Prenom : ");
        lire_ligne(etudiants[i].prenom, sizeof(etudiants[i].prenom));

        printf("Adresse : ");
        lire_ligne(etudiants[i].adresse, sizeof(etudiants[i].adresse));

        printf("Note 1 : ");
        if (scanf("%d", &etudiants[i].note1) != 1)
        {
            printf("Erreur de saisie de note 1.\n");
            return 1;
        }

        printf("Note 2 : ");
        if (scanf("%d", &etudiants[i].note2) != 1)
        {
            printf("Erreur de saisie de note 2.\n");
            return 1;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        /* Format de la ligne dans etudiant.txt */
        snprintf(ligne, sizeof(ligne), "%s;%s;%s;%d;%d",
                 etudiants[i].nom,
                 etudiants[i].prenom,
                 etudiants[i].adresse,
                 etudiants[i].note1,
                 etudiants[i].note2);

        ecrire_dans_fichier("etudiant.txt", ligne);
    }

    printf("\nLes details des etudiants ont ete enregistres dans le fichier etudiant.txt.\n");

    return 0;
}
