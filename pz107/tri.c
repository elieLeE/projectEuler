#include "tri.h"

void trierTabArete(arete tabArete[], int nbreArete){
    qsort(tabArete, nbreArete, sizeof(arete), comparArete);
}

int comparArete(void const *a, void const *b){
    arete *pa = (arete*)a;
    arete *pb = (arete*)b;
    return pa->val - pb->val;
}

