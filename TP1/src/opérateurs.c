#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    // Opérations arithmétiques
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n\n", a % b);  // %% pour afficher %

    // Opérateurs de comparaison
    printf("a == b : %d\n", a == b);   // 1 si vrai, 0 si faux
    printf("a > b : %d\n", a > b);     // 1 si vrai, 0 si faux
    printf("a < b : %d\n", a < b);     // 1 si vrai, 0 si faux
    printf("a != b : %d\n", a != b);   // 1 si vrai, 0 si faux
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n", a <= b);

    return 0;
}
