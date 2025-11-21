#include <stdio.h>
#include <stdint.h>

#define TAILLE 100

typedef struct {
    uint8_t r, g, b, a;
} Couleur;

typedef struct {
    Couleur couleur;
    int count;
} CouleurDistincte;

int couleursEgales(Couleur c1, Couleur c2) {
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

int main() {
    Couleur tab[TAILLE];
    CouleurDistincte distinctes[TAILLE];
    int nbDistinctes = 0;

    // Initialisation aléatoire pour l'exemple
    for (int i = 0; i < TAILLE; i++) {
        tab[i].r = i % 256;
        tab[i].g = (i * 2) % 256;
        tab[i].b = (i * 3) % 256;
        tab[i].a = 255;
    }

    // Comptage des couleurs distinctes
    for (int i = 0; i < TAILLE; i++) {
        int trouve = 0;
        for (int j = 0; j < nbDistinctes; j++) {
            if (couleursEgales(tab[i], distinctes[j].couleur)) {
                distinctes[j].count++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            distinctes[nbDistinctes].couleur = tab[i];
            distinctes[nbDistinctes].count = 1;
            nbDistinctes++;
        }
    }

    // Affichage des couleurs distinctes
    for (int i = 0; i < nbDistinctes; i++) {
        Couleur c = distinctes[i].couleur;
        printf("0x%02x 0x%02x 0x%02x 0x%02x : %d\n",
               c.r, c.g, c.b, c.a, distinctes[i].count);
    }

    return 0;
}
