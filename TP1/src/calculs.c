#include <stdio.h>

int main() {
    int num1, num2;
    char op;

    printf("Entrez num1 : ");
    scanf("%d", &num1);

    printf("Entrez num2 : ");
    scanf("%d", &num2);

    printf("Entrez un operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);  // espace avant %c pour consommer les retours à la ligne

    switch (op) {

        case '+':
            printf("Resultat : %d\n", num1 + num2);
            break;

        case '-':
            printf("Resultat : %d\n", num1 - num2);
            break;

        case '*':
            printf("Resultat : %d\n", num1 * num2);
            break;

        case '/':
            if (num2 == 0) {
                printf("Erreur : division par zero !\n");
            } else {
                printf("Resultat : %d\n", num1 / num2);
            }
            break;

        case '%':
            if (num2 == 0) {
                printf("Erreur : modulo par zero !\n");
            } else {
                printf("Resultat : %d\n", num1 % num2);
            }
            break;

        case '&':
            printf("Resultat (ET binaire) : %d\n", num1 & num2);
            break;

        case '|':
            printf("Resultat (OU binaire) : %d\n", num1 | num2);
            break;

        case '~':
            printf("Resultat (~num1) : %d\n", ~num1);
            printf("Resultat (~num2) : %d\n", ~num2);
            break;

        default:
            printf("Erreur : operateur inconnu.\n");
    }

    return 0;
}


