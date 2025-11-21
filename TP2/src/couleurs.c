#include <stdio.h>

#define NB_COULEURS 10

// Définition d'une structure pour représenter une couleur RGBA
struct Couleur {
    unsigned char r; // Rouge
    unsigned char g; // Vert
    unsigned char b; // Bleu
    unsigned char a; // Alpha
};

int main() {
    struct Couleur couleurs[NB_COULEURS] = {
        {0xef, 0x78, 0x12, 0xff},
        {0x2c, 0xc8, 0x64, 0xff},
        {0x00, 0x00, 0x00, 0xff},
        {0xff, 0xff, 0xff, 0xff},
        {0x12, 0x34, 0x56, 0x99},
        {0xab, 0xcd, 0xef, 0xdd},
        {0x10, 0x20, 0x30, 0x40},
        {0x80, 0x00, 0x80, 0xff},
        {0xfa, 0x80, 0x72, 0xff},
        {0x33, 0x66, 0x99, 0xaa}
    };

    printf("===== Liste des couleurs (RGBA) =====\n\n");

    for (int i = 0; i < NB_COULEURS; i++) {
        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %u\n", couleurs[i].r);
        printf("Vert  : %u\n", couleurs[i].g);
        printf("Bleu  : %u\n", couleurs[i].b);
        printf("Alpha : %u\n\n", couleurs[i].a);
    }

    return 0;
}
