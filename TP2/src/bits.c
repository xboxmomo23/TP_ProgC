#include <stdio.h>

int main() {
    unsigned int d = 0x00101008; // valeur d'exemple
    int taille = sizeof(unsigned int) * 8; // nombre de bits (généralement 32)

    // Calcul des positions à partir de la droite
    int bit4 = taille - 4;   // 4ème bit de gauche
    int bit20 = taille - 20; // 20ème bit de gauche

    // Masque et extraction des bits
    int b4 = (d >> bit4) & 1;
    int b20 = (d >> bit20) & 1;

    // Vérification si les deux bits sont à 1
    if (b4 == 1 && b20 == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
