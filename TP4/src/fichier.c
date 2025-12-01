#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

void lire_fichier(const char *nom_de_fichier)
{
    FILE *f = fopen(nom_de_fichier, "r");
    if (f == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier '%s' en lecture.\n", nom_de_fichier);
        return;
    }

    char buffer[1024];
    printf("Contenu du fichier %s :\n", nom_de_fichier);
    while (fgets(buffer, (int)sizeof(buffer), f) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(f);
}

void ecrire_dans_fichier(const char *nom_de_fichier, const char *message)
{
    /* mode "a" : on ajoute a la fin (utile pour la base etudiant.txt) */
    FILE *f = fopen(nom_de_fichier, "a");
    if (f == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier '%s' en ecriture.\n", nom_de_fichier);
        return;
    }

    fprintf(f, "%s\n", message);
    fclose(f);

    printf("Le message a ete ecrit dans le fichier %s.\n", nom_de_fichier);
}
