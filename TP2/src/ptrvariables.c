/* ptrvariables.c
 * Affiche adresse et valeur (en hex) de différentes variables,
 * avant et après manipulation via des pointeurs.
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

int main(void) {
    /* Variables de base */
    char                c   = 'A';                 /* 0x41 */
    short               s   = 12345;               /* 0x3039 */
    int                 i   = 0xA47865FF;          /* valeur exemple (32-bit) */
    long                li  = 123456789L;          /* dépend de l'architecture */
    long long           lli = 123456789012345LL;   /* 64-bit */
    float               f   = 2.0f;                /* représentation IEEE-754 */
    double              d   = 3.141592653589793;
    long double         ld  = 1.234567890123456789L;

    /* Pointeurs vers ces variables */
    char        *pc  = &c;
    short       *ps  = &s;
    int         *pi  = &i;
    long        *pli = &li;
    long long   *plli= &lli;
    float       *pf  = &f;
    double      *pd  = &d;
    long double *pld = &ld;

    /* Buffers pour extraire représentations bit-à-bit */
    uint32_t u32;
    uint64_t u64;
    unsigned char buf_ld[sizeof(long double)];

    /* Affichage avant manipulation */
    printf("===== Avant la manipulation =====\n\n");

    printf("Adresse de c  : %p, Valeur de c  : 0x%02" PRIx8 "\n",
           (void*)pc, (uint8_t)*pc);

    printf("Adresse de s  : %p, Valeur de s  : 0x%04" PRIx16 "\n",
           (void*)ps, (uint16_t)*ps);

    printf("Adresse de i  : %p, Valeur de i  : 0x%08" PRIx32 "\n",
           (void*)pi, (uint32_t)*pi);

    printf("Adresse de li : %p, Valeur de li : 0x%0*" PRIx64 "\n",
           (void*)pli, (int)(2 * sizeof(long)), (uint64_t)*pli);
    /* Note : on affiche li en tant que 64 bits casté pour visibilité portable. */

    printf("Adresse de lli: %p, Valeur de lli: 0x%016" PRIx64 "\n",
           (void*)plli, (uint64_t)*plli);

    /* Float -> copier bits dans u32 */
    memcpy(&u32, pf, sizeof(u32));
    printf("Adresse de f  : %p, Valeur de f  (bits) : 0x%08" PRIx32 " (valeur = %f)\n",
           (void*)pf, u32, *pf);

    /* Double -> copier bits dans u64 */
    memcpy(&u64, pd, sizeof(u64));
    printf("Adresse de d  : %p, Valeur de d  (bits) : 0x%016" PRIx64 " (valeur = %f)\n",
           (void*)pd, u64, *pd);

    /* Long double -> afficher octet par octet (taille architect. dépendante) */
    memcpy(buf_ld, pld, sizeof(buf_ld));
    printf("Adresse de ld : %p, Valeur de ld (octets) : 0x", (void*)pld);
    /* On affiche les octets du plus significatif au moins significatif pour lisibilité */
    for (int idx = (int)sizeof(buf_ld) - 1; idx >= 0; --idx) {
        printf("%02x", (unsigned int)buf_ld[idx]);
    }
    printf(" (valeur = %Lg)\n\n", *pld);

    /* ----- Manipulation via pointeurs ----- */
    /* Exemple de modifications via les pointeurs (toujours par déréférencement) */
    *pc  = *pc + 1;           /* 'A' -> 'B' */
    *ps  = *ps - 1;           /* 12345 -> 12344 */
    *pi  = *pi ^ 0x1;         /* flip du LSB */
    *pli = *pli + 1;          /* incrément */
    *plli= *plli * 2;         /* double la valeur */
    *pf  = 1.0f;              /* change la valeur float */
    *pd  = 2.718281828459045; /* change la valeur double */
    *pld = 0.0L;              /* change la valeur long double */

    /* Récupération des nouvelles représentations bit-à-bit */
    memcpy(&u32, pf, sizeof(u32));
    memcpy(&u64, pd, sizeof(u64));
    memcpy(buf_ld, pld, sizeof(buf_ld));

    /* Affichage après manipulation */
    printf("===== Après la manipulation via pointeurs =====\n\n");

    printf("Adresse de c  : %p, Valeur de c  : 0x%02" PRIx8 " (caractere = '%c')\n",
           (void*)pc, (uint8_t)*pc, *pc);

    printf("Adresse de s  : %p, Valeur de s  : 0x%04" PRIx16 " (décimal = %" PRId16 ")\n",
           (void*)ps, (uint16_t)*ps, *ps);

    printf("Adresse de i  : %p, Valeur de i  : 0x%08" PRIx32 " (décimal = %" PRId32 ")\n",
           (void*)pi, (uint32_t)*pi, *pi);

    printf("Adresse de li : %p, Valeur de li : 0x%0*" PRIx64 " (décimal = %ld)\n",
           (void*)pli, (int)(2 * sizeof(long)), (uint64_t)*pli, *pli);

    printf("Adresse de lli: %p, Valeur de lli: 0x%016" PRIx64 " (décimal = %lld)\n",
           (void*)plli, (uint64_t)*plli, *plli);

    printf("Adresse de f  : %p, Valeur de f  (bits) : 0x%08" PRIx32 " (valeur = %f)\n",
           (void*)pf, u32, *pf);

    printf("Adresse de d  : %p, Valeur de d  (bits) : 0x%016" PRIx64 " (valeur = %f)\n",
           (void*)pd, u64, *pd);

    printf("Adresse de ld : %p, Valeur de ld (octets) : 0x", (void*)pld);
    for (int idx = (int)sizeof(buf_ld) - 1; idx >= 0; --idx) {
        printf("%02x", (unsigned int)buf_ld[idx]);
    }
    printf(" (valeur = %Lg)\n", *pld);

    return 0;
}
