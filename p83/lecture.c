#include "lecture.h"

FILE* ouvFichier(char* name){
    FILE* f = fopen(name, "r");
    if(f == NULL){
	fprintf(stderr, "impossible d'ouvrir le fichier %s\n", name);
	exit(0);
    }
    return f;
}

void fermerFichier(FILE **f){
    fclose(*f);
}

void lireMatrice(FILE* fichier, unsigned int* matrice[80]){
    int i, j;
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    fscanf(fichier, "%d", &matrice[i][j]);
	}
    }
}
