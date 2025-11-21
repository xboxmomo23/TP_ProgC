#include <stdio.h>

int main() {
    // Déclaration des chaînes
    char str1[100] = "Hello";
    char str2[100] = " World!";
    char copie[100];
    char concat[200];

    // --- 1. Calcul de la longueur de str1 ---
    int longueur = 0;
    while (str1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de la première chaîne '%s' : %d\n", str1, longueur);

    // --- 2. Copier str1 dans copie ---
    int i = 0;
    while (str1[i] != '\0') {
        copie[i] = str1[i];
        i++;
    }
    copie[i] = '\0'; // Terminer par le caractère nul
    printf("Copie de la première chaîne : '%s'\n", copie);

    // --- 3. Concaténer str1 et str2 dans concat ---
    i = 0;
    int j = 0;
    // Copier str1 dans concat
    while (str1[i] != '\0') {
        concat[i] = str1[i];
        i++;
    }
    // Ajouter str2 après str1
    while (str2[j] != '\0') {
        concat[i] = str2[j];
        i++;
        j++;
    }
    concat[i] = '\0'; // Terminer par le caractère nul
    printf("Concaténation des deux chaînes : '%s'\n", concat);

    return 0;
}
