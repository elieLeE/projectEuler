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

void searchDescente(unsigned int** matrice, unsigned int** tabDescente, int col){
    unsigned int i;
    tabDescente[0][col] = matrice[0][col] + matrice[0][col-1];
    for(i=1; i<TAILLE_MATRICE; i++){
	tabDescente[i][col] = minAB(tabDescente[i-1][col], matrice[i][col-1]) + matrice[i][col];
    }
}

void searchMonte(unsigned int** matrice, unsigned int** tabMonte, int col){
    int i;
    tabMonte[TAILLE_MATRICE-1][col] = matrice[TAILLE_MATRICE-1][col] + matrice[TAILLE_MATRICE-1][col-1];
    for(i=TAILLE_MATRICE-2; i>=0; i--){
	tabMonte[i][col] = minAB(tabMonte[i+1][col], matrice[i][col-1]) + matrice[i][col];
    }
}

int shorterWay(unsigned int** matrice){
    unsigned int **tabMonte, **tabDescente;
    allocTab2D(&tabMonte);
    allocTab2D(&tabDescente);

    unsigned int i, j, min;

    for(j=1; j<TAILLE_MATRICE; j++){
	searchDescente(matrice, tabDescente, j);
	searchMonte(matrice, tabMonte, j);
	for(i=0; i<TAILLE_MATRICE; i++){
	    matrice[i][j] = minAB(tabMonte[i][j], tabDescente[i][j]);
	}
    }

    min = matrice[0][TAILLE_MATRICE-1];
    for(i=0; i<TAILLE_MATRICE; i++){
	if(min > matrice[i][TAILLE_MATRICE-1]){
	    min = matrice[i][TAILLE_MATRICE-1];
	}
    }

    liberation(tabDescente);
    liberation(tabMonte);
    return min;
}
