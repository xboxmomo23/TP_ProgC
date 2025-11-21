#include <stdio.h>

int main() {
    int a = 2; // base
    int b = 3; // exposant
    int resultat = 1; // initialisation à 1 car a^0 = 1

    // Boucle pour calculer a^b
    for (int i = 1; i <= b; i++) {
        resultat *= a; // multiplie le résultat par a à chaque itération
    }

    // Affichage du résultat
    printf("%d élevé à la puissance %d = %d\n", a, b, resultat);

    return 0;
}
