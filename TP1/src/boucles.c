#include <stdio.h>

int main() {
    int compteur = 5; // tu peux tester avec n'importe quelle valeur < 10

    for (int i = 1; i <= compteur; i++) {        // lignes
        for (int j = 1; j <= i; j++) {          // colonnes
            if (i % 2 == 0 && j % 2 == 0) {     // pour mettre des #
                printf("# ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0;
}
