#ifndef LISTE_H
#define LISTE_H

#include <stdint.h>

struct couleur
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

struct element_couleur
{
    struct couleur valeur;
    struct element_couleur *suivant;
};

struct liste_couleurs
{
    struct element_couleur *tete;
};

void init_liste(struct liste_couleurs *liste);
void insertion(const struct couleur *c, struct liste_couleurs *liste);
void parcours(const struct liste_couleurs *liste);
void liberer_liste(struct liste_couleurs *liste);

#endif /* LISTE_H */
