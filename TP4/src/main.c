
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Operator.h"
#include "fichier.h"
#include "liste.h"

/* petite fonction utilitaire pour lire une ligne (avec espaces) */
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

/* ====== Exercice 4.1 ====== */
void exercice_4_1(void)
{
    int num1, num2;
    char op;

    printf("=== Exercice 4.1 : Calcul avec operateurs ===\n");
    printf("Entrez num1 : ");
    if (scanf("%d", &num1) != 1)
    {
        printf("Lecture de num1 impossible.\n");
        return;
    }

    printf("Entrez num2 : ");
    if (scanf("%d", &num2) != 1)
    {
        printf("Lecture de num2 impossible.\n");
        return;
    }

    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    /* consommer l'espace / fin de ligne restante */
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    op = (char)getchar();

    int resultat;
    switch (op)
    {
    case '+':
        resultat = somme(num1, num2);
        break;
    case '-':
        resultat = difference(num1, num2);
        break;
    case '*':
        resultat = produit(num1, num2);
        break;
    case '/':
        resultat = quotient(num1, num2);
        break;
    case '%':
        resultat = modulo(num1, num2);
        break;
    case '&':
        resultat = et(num1, num2);
        break;
    case '|':
        resultat = ou(num1, num2);
        break;
    case '~':
        resultat = negation(num1, num2);
        break;
    default:
        printf("Operateur inconnu.\n");
        return;
    }

    printf("Resultat : %d\n", resultat);
}

/* ====== Exercice 4.2 ====== */
void exercice_4_2(void)
{
    int choix = 0;
    char buffer_nom[256];
    char buffer_message[1024];

    printf("=== Exercice 4.2 : Gestion de fichiers ===\n");

    while (1)
    {
        printf("\nQue souhaitez-vous faire ?\n");
        printf("1. Lire un fichier\n");
        printf("2. Ecrire dans un fichier\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1)
        {
            printf("Entree invalide.\n");
            /* vider le buffer stdin */
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        if (choix == 0)
        {
            break;
        }
        else if (choix == 1)
        {
            printf("Entrez le nom du fichier a lire : ");
            lire_ligne(buffer_nom, sizeof(buffer_nom));
            lire_fichier(buffer_nom);
        }
        else if (choix == 2)
        {
            printf("Entrez le nom du fichier dans lequel vous souhaitez ecrire : ");
            lire_ligne(buffer_nom, sizeof(buffer_nom));

            printf("Entrez le message a ecrire : ");
            lire_ligne(buffer_message, sizeof(buffer_message));

            ecrire_dans_fichier(buffer_nom, buffer_message);
        }
        else
        {
            printf("Choix inconnu.\n");
        }
    }
}

/* ====== Exercice 4.7 ====== */
void exercice_4_7(void)
{
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);

    printf("=== Exercice 4.7 : Liste de couleurs ===\n");

    /* Creation de 10 couleurs d'exemple */
    struct couleur couleurs[10] = {
        {0xFF, 0x00, 0x00, 0xFF}, /* rouge */
        {0x00, 0xFF, 0x00, 0xFF}, /* vert */
        {0x00, 0x00, 0xFF, 0xFF}, /* bleu */
        {0xFF, 0xFF, 0x00, 0xFF}, /* jaune */
        {0xFF, 0x00, 0xFF, 0xFF}, /* magenta */
        {0x00, 0xFF, 0xFF, 0xFF}, /* cyan */
        {0x80, 0x80, 0x80, 0xFF}, /* gris */
        {0x00, 0x00, 0x00, 0xFF}, /* noir */
        {0xFF, 0xFF, 0xFF, 0xFF}, /* blanc */
        {0x80, 0x00, 0x80, 0xFF}  /* violet */
    };

    for (int i = 0; i < 10; i++)
    {
        insertion(&couleurs[i], &ma_liste);
    }

    printf("Liste des couleurs :\n");
    parcours(&ma_liste);

    liberer_liste(&ma_liste);
}

/* ====== main generique ====== */

int main(void)
{
    int choix = -1;

    while (1)
    {
        printf("\n=== Menu principal TP4 ===\n");
        printf("1. Exercice 4.1 - Operateurs\n");
        printf("2. Exercice 4.2 - Gestion de fichiers\n");
        printf("3. Exercice 4.7 - Liste de couleurs\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1)
        {
            printf("Entree invalide.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }

        switch (choix)
        {
        case 1:
            exercice_4_1();
            break;
        case 2:
            exercice_4_2();
            break;
        case 3:
            exercice_4_7();
            break;
        case 0:
            printf("Au revoir.\n");
            return 0;
        default:
            printf("Choix inconnu.\n");
            break;
        }
    }

    return 0;
}
