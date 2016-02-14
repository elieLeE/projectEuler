#include "matrice.h"

void affMatrice(unsigned int** matrice){
    int i, j;
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    printf("%d, ", matrice[i][j]);
	}
	printf("\n");
    }
}

unsigned int minAB(unsigned int a, unsigned int b){
    if(a>b){
	return b;
    }
    return a;
}

int shorterWay(unsigned int** matrice){
    unsigned int** tab = (unsigned int**)allocTab2D(TAILLE_MATRICE, TAILLE_MATRICE, sizeof(unsigned int));

    int i, j, min;
    tab[0][0] = matrice[0][0];

    for(i=1; i<TAILLE_MATRICE; i++){
	tab[0][i] = tab[0][i-1] + matrice[0][i];
	tab[i][0] = tab[i-1][0] + matrice[i][0];
    }

    for(i=1; i<TAILLE_MATRICE; i++){
	tab[i][i] = minAB(tab[i-1][i], tab[i][i-1]) + matrice[i][i];
	for(j=i+1; j<TAILLE_MATRICE; j++){
	    tab[i][j] = minAB(tab[i-1][j], tab[i][j-1]) + matrice[i][j];
	    tab[j][i] = minAB(tab[j-1][i], tab[j][i-1]) + matrice[j][i];
	}
    }
    min = tab[TAILLE_MATRICE-1][TAILLE_MATRICE-1];
    liberationTab2D((void**)tab, TAILLE_MATRICE);
    return min;
}
