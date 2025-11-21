#include <stdio.h>
#include <string.h>

#define NB_ETUDIANTS 5
#define TAILLE 100

// Définition de la structure Étudiant
struct Etudiant {
    char nom[TAILLE];
    char prenom[TAILLE];
    char adresse[TAILLE];
    float note1;  // Programmation C
    float note2;  // Système d'exploitation
};

int main() {
    struct Etudiant etudiants[NB_ETUDIANTS];

    // Initialisation des étudiants avec strcpy
    strcpy(etudiants[0].nom, "Dupont");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "20, Boulevard Niels Bohr, Lyon");
    etudiants[0].note1 = 16.5;
    etudiants[0].note2 = 12.1;

    strcpy(etudiants[1].nom, "Martin");
    strcpy(etudiants[1].prenom, "Pierre");
    strcpy(etudiants[1].adresse, "22, Boulevard Niels Bohr, Lyon");
    etudiants[1].note1 = 14.0;
    etudiants[1].note2 = 14.1;

    strcpy(etudiants[2].nom, "Moreau");
    strcpy(etudiants[2].prenom, "Sofia");
    strcpy(etudiants[2].adresse, "15, Rue de Marseille, Paris");
    etudiants[2].note1 = 17.2;
    etudiants[2].note2 = 13.8;

    strcpy(etudiants[3].nom, "Lambert");
    strcpy(etudiants[3].prenom, "Lucas");
    strcpy(etudiants[3].adresse, "8, Avenue du Pra
