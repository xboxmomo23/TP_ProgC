#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *liste)
{
    if (liste != NULL)
    {
        liste->tete = NULL;
    }
}

void insertion(const struct couleur *c, struct liste_couleurs *liste)
{
    if (liste == NULL || c == NULL)
    {
        return;
    }

    struct element_couleur *nouveau = (struct element_couleur *)malloc(sizeof(struct element_couleur));
    if (nouveau == NULL)
    {
        printf("Erreur : allocation memoire impossible pour un nouvel element.\n");
        return;
    }

    nouveau->valeur = *c;
    nouveau->suivant = liste->tete; /* insertion en tete */
    liste->tete = nouveau;
}

void parcours(const struct liste_couleurs *liste)
{
    if (liste == NULL)
    {
        return;
    }

    const struct element_couleur *courant = liste->tete;
    int index = 0;

    while (courant != NULL)
    {
        printf("Couleur %d : R=0x%02X, G=0x%02X, B=0x%02X, A=0x%02X\n",
               index,
               courant->valeur.r,
               courant->valeur.g,
               courant->valeur.b,
               courant->valeur.a);
        courant = courant->suivant;
        index++;
    }
}

void liberer_liste(struct liste_couleurs *liste)
{
    if (liste == NULL)
    {
        return;
    }

    struct element_couleur *courant = liste->tete;
    while (courant != NULL)
    {
        struct element_couleur *suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }

    liste->tete = NULL;
}
