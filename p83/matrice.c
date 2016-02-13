#include "matrice.h"

void affMatrice(unsigned int** matrice){
    int i, j;
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    printf("%d, ", matrice[i][j]);
	}
	printf("\n");
    }
    printf("\n");
}
