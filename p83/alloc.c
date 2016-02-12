#include "alloc.h"

void allocTab2D(unsigned int*** matrice){
    int i;
    *matrice = calloc(80, sizeof(unsigned int*));
    if(matrice == NULL){
	fprintf(stderr, "allocation non effectuée, fichier %s, ligne %d\n", __FILE__, __LINE__);
	exit(0);
    }

    for(i=0; i<TAILLE_MATRICE; i++){
	(*matrice)[i] = calloc(80, sizeof(unsigned int));
	if((*matrice)[i] == NULL){
	    fprintf(stderr, "allocation non effectuée, fichier %s, ligne %d\n", __FILE__, __LINE__);
	    exit(0);
	}
    }
}

void allocGraphe(sommet*** g){
    int i;
    *g = calloc(80, sizeof(sommet*));
    if(g == NULL){
	fprintf(stderr, "allocation non effectuée, fichier %s, ligne %d\n", __FILE__, __LINE__);
	exit(0);
    }

    for(i=0; i<TAILLE_MATRICE; i++){
	(*g)[i] = calloc(80, sizeof(sommet));
	if((*g)[i] == NULL){
	    fprintf(stderr, "allocation non effectuée, fichier %s, ligne %d\n", __FILE__, __LINE__);
	    exit(0);
	}
    }
}

void liberationTab2D(unsigned int** matrice){
    int i;
    for(i=0; i<TAILLE_MATRICE; i++){
	free(matrice[i]);
    }
    free(matrice);
}
    
void liberationGraphe(sommet** g){
    int i;
    for(i=0; i<TAILLE_MATRICE; i++){
	free(g[i]);
    }
    free(g);
}
