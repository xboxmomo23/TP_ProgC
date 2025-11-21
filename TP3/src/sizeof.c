#include <stdio.h>

int main() {
    printf("Taille des types de base et pointeurs sur une machine 64 bits :\n\n");

    printf("int       : %zu octets\n", sizeof(int));
    printf("int*      : %zu octets\n", sizeof(int*));
    printf("int**     : %zu octets\n", sizeof(int**));
    printf("char      : %zu octets\n", sizeof(char));
    printf("char*     : %zu octets\n", sizeof(char*));
    printf("char**    : %zu octets\n", sizeof(char**));
    printf("char***   : %zu octets\n", sizeof(char***));
    printf("float     : %zu octets\n", sizeof(float));
    printf("float*    : %zu octets\n", sizeof(float*));
    printf("float**   : %zu octets\n", sizeof(float**));
    printf("float***  : %zu octets\n", sizeof(float***));

    return 0;
}
