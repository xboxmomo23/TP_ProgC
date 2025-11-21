#include <stdio.h>

#define NB_ETUDIANTS 5
#define TAILLE 50

int main() {
    char noms[NB_ETUDIANTS][TAILLE] = {
        "Martin", "Dupont", "Moreau", "Lambert", "Bernard"
    };

    char prenoms[NB_ETUDIANTS][TAILLE] = {
        "Alice", "Jean", "Sofia", "Lucas", "Nadia"
    };

    char adresses[NB_ETUDIANTS][TAILLE] = {
        "12 Rue de Paris",
        "5 Avenue de Lyon",
        "8 Boulevard du Nord",
        "21 Rue Victor Hugo",
        "3 Chemin des Fleurs"
    };

    float notes_progC[NB_ETUDIANTS] = {14.5, 12.0, 16.75, 9.5, 18.0};
    float notes_sys[NB_ETUDIANTS]   = {13.0, 11.5, 15.25, 10.0, 17.5};

    printf("===== Liste des etudiants =====\n\n");

    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom          : %s\n", noms[i]);
        printf("Prenom       : %s\n", prenoms[i]);
        printf("Adresse      : %s\n", adresses[i]);
        printf("Note C       : %.2f\n", notes_progC[i]);
        printf("Note Systeme : %.2f\n\n", notes_sys[i]);
    }

    return 0;
}
