#include <stdio.h>

#define TAILLE 100

int rechercheDichotomique(int tab[], int n, int valeur) {
    int gauche = 0;
    int droite = n - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (tab[milieu] == valeur) {
            return 1; // trouvé
        } else if (tab[milieu] < valeur) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    return 0; // non trouvé
}

int main() {
    int tab[TAILLE];

    // Initialisation du tableau trié
    for (int i = 0; i < TAILLE; i++) {
        tab[i] = i * 2 - 50; // exemple : -50, -48, -46 ...
    }

    // Affichage du tableau
    printf("Tableau trié :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    // Lecture de la valeur à rechercher
    int valeur;
    printf("Entrez l'entier à rechercher : ");
    scanf("%d", &valeur);

    // Recherche dichotomique
    if (rechercheDichotomique(tab, TAILLE, valeur)) {
        printf("Résultat : entier présent\n");
    } else {
        printf("Résultat : entier absent\n");
    }

    return 0;
}
