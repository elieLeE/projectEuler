#include "alloc.h"

void allocGraphe(sommet*** g){
    int i;
    *g = my_calloc(80*sizeof(sommet*));
    for(i=0; i<TAILLE_MATRICE; i++){
	(*g)[i] = my_calloc(80*sizeof(sommet));
    }
}

void liberationGraphe(sommet** g){
    int i;
    for(i=0; i<TAILLE_MATRICE; i++){
	free(g[i]);
    }
    free(g);
}
