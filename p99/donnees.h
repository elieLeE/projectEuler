#ifndef _DONNEES_H_
#define _DONNEES_H_

#include <gmp.h>

#define MODE 0

typedef struct duo duo;
struct duo{
    int a, b;
    int lig;
#if MODE
    mpz_t nbre;
#else
    double nbre;
#endif
};

#endif
