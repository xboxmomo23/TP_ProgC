#include <stdio.h>

#define NB_PHRASES 10
#define TAILLE_MAX 100

int comparerPhrases(char *p1, char *p2) {
    int i = 0;
    while (p1[i] != '\0' && p2[i] != '\0') {
        if (p1[i] != p2[i])
            return 0; // différent
        i++;
    }
    return p1[i] == '\0' && p2[i] == '\0'; // vrai si fin des deux
}

int main() {
    char phrases[NB_PHRASES][TAILLE_MAX] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };

    char recherche[TAILLE_MAX];
    printf("Entrez la phrase à rechercher :\n");
    fgets(recherche, TAILLE_MAX, stdin);

    // Retirer le \n de fgets
    int i = 0;
    while (recherche[i] != '\0') {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
        i++;
    }

    // Recherche
    int trouve = 0;
    for (i = 0; i < NB_PHRASES; i++) {
        if (comparerPhrases(phrases[i], recherche)) {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("Phrase trouvée\n");
    else
        printf("Phrase non trouvée\n");

    return 0;
}
