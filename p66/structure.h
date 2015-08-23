#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct alpha alpha;
typedef struct search_sol search_sol;

struct alpha{
    long long a, b, n;
};

struct search_sol{
    long long norme, m;
    struct alpha alp;
};

long long normeAlpha(alpha a);
void alphaCarreSur2(alpha *a);
void alphaCubeSur8(alpha *a);
void alphaSixSur64(alpha *a);
char* visuAlpha(alpha a);
alpha nextAlpha(struct search_sol sol, long long m);
long long searchM(struct search_sol sol);
alpha searchSol(long long n);
alpha searchSolRec(struct search_sol s);


#endif
