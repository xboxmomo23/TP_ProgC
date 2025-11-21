#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 11

int main() {
    int tabInt[TAILLE];
    float tabFloat[TAILLE];

    srand(time(NULL)); // Initialisation de la graine aléatoire

    /* Remplissage des tableaux avec des valeurs aléatoires */
    for (int i = 0; i < TAILLE; i++) {
        *(tabInt + i) = rand() % 101;          // int aléatoire entre 0 et 100
        *(tabFloat + i) = (float)(rand() % 1000) / 100.0f; // float entre 0.0 et 9.99
    }

    /* Affichage avant multiplication */
    printf("Tableau d'entiers avant multiplication par 3 :\n");
    for (int *p = tabInt; p < tabInt + TAILLE; p++) {
        printf("%d ", *p);
    }
    printf("\n\n");

    printf("Tableau de float avant multiplication par 3 :\n");
    for (float *p = tabFloat; p < tabFloat + TAILLE; p++) {
        printf("%.2f ", *p);
    }
    printf("\n\n");

    /* Multiplication par 3 des valeurs dont l'indice est divisible par 2 */
    for (int i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            *(tabInt + i) *= 3;
            *(tabFloat + i) *= 3.0f;
        }
    }

    /* Affichage après multiplication */
    printf("Tableau d'entiers après multiplication par 3 :\n");
    for (int *p = tabInt; p < tabInt + TAILLE; p++) {
        printf("%d ", *p);
    }
    printf("\n\n");

    printf("Tableau de float après multiplication par 3 :\n");
    for (float *p = tabFloat; p < tabFloat + TAILLE; p++) {
        printf("%.2f ", *p);
    }
    printf("\n");

    return 0;
}
