#include <stdio.h>

int main() {
    int n = 7; // nombre de termes à générer
    int i;

    int u0 = 0, u1 = 1; // premiers termes
    int un;             // terme courant

    printf("Suite de Fibonacci jusqu'au terme %d : ", n);

    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", u0);
        } else if (i == 1) {
            printf(", %d", u1);
        } else {
            un = u0 + u1;        // calcul du terme courant
            printf(", %d", un);
            u0 = u1;             // mise à jour des deux derniers termes
            u1 = un;
        }
    }

    printf("\n");

    return 0;
}
