#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tab[TAILLE];
    int valeur;
    int trouve = 0;

    srand(time(NULL));

    // Remplissage tableau aléatoire
    for (int i = 0; i < TAILLE; i++) {
        tab[i] = rand() % 1000;
    }

    // Affichage du tableau
    printf("Tableau :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    // Lecture valeur à rechercher
    printf("Entrez l'entier à rechercher : ");
    scanf("%d", &valeur);

    // Recherche linéaire
    for (int i = 0; i < TAILLE; i++) {
        if (tab[i] == valeur) {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("Résultat : entier présent\n");
    else
        printf("Résultat : entier absent\n");

    return 0;
}
