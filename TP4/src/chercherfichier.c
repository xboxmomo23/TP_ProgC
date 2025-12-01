#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[])
{
    char nom_fichier[256];

    if (argc >= 2)
    {
        strncpy(nom_fichier, argv[1], sizeof(nom_fichier) - 1);
        nom_fichier[sizeof(nom_fichier) - 1] = '\0';
    }
    else
    {
        printf("Entrez le nom du fichier dans lequel chercher : ");
        lire_ligne(nom_fichier, sizeof(nom_fichier));
    }

    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier '%s'.\n", nom_fichier);
        return 1;
    }

    char phrase[256];
    printf("Entrez la phrase que vous souhaitez rechercher : ");
    lire_ligne(phrase, sizeof(phrase));

    size_t len_phrase = strlen(phrase);
    if (len_phrase == 0)
    {
        printf("Phrase vide, rien a chercher.\n");
        fclose(f);
        return 0;
    }

    printf("\nResultats de la recherche :\n");

    char ligne[1024];
    int num_ligne = 0;
    int trouve_global = 0;

    while (fgets(ligne, (int)sizeof(ligne), f) != NULL)
    {
        num_ligne++;
        int count = 0;

        char *pos = ligne;
        while ((pos = strstr(pos, phrase)) != NULL)
        {
            count++;
            pos += len_phrase;
        }

        if (count > 0)
        {
            printf("Ligne %d, %d fois\n", num_ligne, count);
            trouve_global = 1;
        }
    }

    if (!trouve_global)
    {
        printf("La phrase n'a pas ete trouvee dans le fichier.\n");
    }

    fclose(f);
    return 0;
}
