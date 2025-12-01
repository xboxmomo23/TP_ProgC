#include <stdio.h>
#include <stdlib.h>
#include "Operator.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage : %s operateur nombre1 nombre2\n", argv[0]);
        printf("Exemple : %s + 10 5\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    int resultat;

    switch (op)
    {
    case '+':
        resultat = somme(num1, num2);
        break;
    case '-':
        resultat = difference(num1, num2);
        break;
    case '*':
        resultat = produit(num1, num2);
        break;
    case '/':
        resultat = quotient(num1, num2);
        break;
    case '%':
        resultat = modulo(num1, num2);
        break;
    case '&':
        resultat = et(num1, num2);
        break;
    case '|':
        resultat = ou(num1, num2);
        break;
    case '~':
        resultat = negation(num1, num2);
        break;
    default:
        printf("Operateur inconnu : %c\n", op);
        return 1;
    }

    printf("Resultat : %d\n", resultat);
    return 0;
}
