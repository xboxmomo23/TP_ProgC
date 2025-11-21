#include <stdio.h>

int main() {
    int num;

    printf("Entrez un nombre entier : ");
    scanf("%d", &num);

    // On affiche les bits du bit 31 (MSB) au bit 0 (LSB)
    printf("Representation binaire de %d : ", num);

    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;   // Décalage à droite + masque
        printf("%d", bit);

        // Optionnel : séparer en groupes de 4 bits pour lisibilité
        if (i % 4 == 0) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}
