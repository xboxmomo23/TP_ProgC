#include <stdio.h>

/* Definition de la fonction factorielle (recopie de l'énoncé + tests) */
int factorielle(int num)
{
    if (num == 0)
    {
        printf("fact(0): 1\n");
        return 1;
    }
    else
    {
        int valeur = num * factorielle(num - 1);
        printf("fact(%d): %d\n", num, valeur);
        return valeur;
    }
}

int main(void)
{
    int valeurs_a_tester[] = {0, 1, 3, 5, 7};
    int taille = (int)(sizeof(valeurs_a_tester) / sizeof(valeurs_a_tester[0]));

    for (int i = 0; i < taille; i++)
    {
        int n = valeurs_a_tester[i];
        printf("\nCalcul de %d! :\n", n);
        int res = factorielle(n);
        printf("Resultat final pour %d! = %d\n", n, res);
    }

    return 0;
}
