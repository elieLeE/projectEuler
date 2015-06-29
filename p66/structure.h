#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct alpha alpha;
typedef struct search_sol search_sol;

struct alpha{
    long a, b, n;
};

struct search_sol{
    long norme, m;
    struct alpha alp;
};

long normeAlpha(alpha a);
long alphaCarreSur2(alpha a);
long alphaCubeSur8(alpha a);
char* visuAlpha(alpha a);
long alphaSixSur64(alpha a);
alpha nextAlpha(struct search_sol sol, long m);
long searchM(struct search_sol sol);
long searchSol(long n);
long searchSolRec(struct search_sol s);

long searchSol(long n);

#endif
