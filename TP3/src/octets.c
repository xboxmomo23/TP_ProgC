#include <stdio.h>
#include <string.h>

int main() {
    short s = 0x0203;
    int i = 0x01020304;
    long li = 0x0102030405060708L;
    float f = 3.14f;
    double d = 3.14;
    long double ld = 3.14L;

    unsigned char *p;

    // Short
    printf("Octets de short :\n");
    p = (unsigned char*)&s;
    for (size_t j = 0; j < sizeof(s); j++) {
        printf("%02x ", p[j]);
    }
    printf("\n\n");

    // Int
    printf("Octets de int :\n");
    p = (unsigned char*)&i;
    for (size_t j = 0; j < sizeof(i); j++) {
        printf("%02x ", p[j]);
    }
    printf("\n\n");

    // Long int
    printf("Octets de long int :\n");
    p = (unsigned char*)&li;
    for (size_t j = 0; j < sizeof(li); j++) {
        printf("%02x ", p[j]);
    }
    printf("\n\n");

    // Float
    printf("Octets de float :\n");
    p = (unsigned char*)&f;
    for (size_t j = 0; j < sizeof(f); j++) {
        printf("%02x ", p[j]);
    }
    printf("\n\n");

    // Double
    printf("Octets de double :\n");
    p = (unsigned char*)&d;
    for (size_t j = 0; j < sizeof(d); j++) {
        printf("%02x ", p[j]);
    }
    printf("\n\n");

    // Long double
    printf("Octets de long double :\n");
    p = (unsigned char*)&ld;
    for (size_t j = 0; j < sizeof(ld); j++) {
        printf("%02x ", p[j]);
    }
    printf("\n");

    return 0;
}
