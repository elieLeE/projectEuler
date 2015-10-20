#include "memoire.h"

void* my_malloc(int taille){
    void* p = malloc(taille);
    if(p==NULL){
	fprintf(stderr, "allocation impossible, fichier %s, ligne %d\n", __FILE__, __LINE__);
    }
    return p;
}

void* my_realloc(void* p, int taille){
    return realloc(p, taille);
}
