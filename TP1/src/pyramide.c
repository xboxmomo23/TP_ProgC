 #include <stdio.h>

int main() {
    int n = 5; // Hauteur de la pyramide
    int i, j;

    for (i = 1; i <= n; i++) {
        // Afficher les espaces pour centrer la pyramide
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Afficher les nombres croissants de 1 à i
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Afficher les nombres décroissants de i-1 à 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n"); // passer à la ligne suivante
    }

    printf("La génération de la pyramide est terminée.\n");

    return 0;
}
