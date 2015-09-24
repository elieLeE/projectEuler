#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <gmp.h>

typedef struct alpha alpha;
typedef struct search_sol search_sol;

struct alpha{
    mpz_t a, b, n;
};

struct search_sol{
    mpz_t norme, m;
    struct alpha alp;
};

mpz_t normeAlpha(alpha a);
void alphaCarreSur2(alpha *a);
void alphaCubeSur8(alpha *a);
void alphaSixSur64(alpha *a);
char* visuAlpha(alpha a);
alpha nextAlpha(struct search_sol sol, mpz_t m);
mpz_t searchM(struct search_sol sol);
alpha searchSol(int  n);
alpha searchSolRec(struct search_sol s);


#endif
