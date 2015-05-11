#include "grille.h"

char nbreDoublonLigne(char ligne[NBRE_COL]){
    char i = 0, nbre_doublon = 0;
    char tab[NBRE_COL] = {0};

    for(i=0; i<NBRE_COL; i++){
	if((++tab[ligne[i]-1]) > 1){
	    //printf("i : %d => doublon\n", i);
	    nbre_doublon++;
	}
    }
    return nbre_doublon;
}

char nbreDoublonCol(char grille[NBRE_LIGNE][NBRE_COL], char num_col){
    char i = 0, nbre_doublon = 0;
    char tab[NBRE_LIGNE] = {0};
    
    for(i=0; i<NBRE_LIGNE; i++){
	if((++tab[grille[i][num_col]-1]) > 1){
	    //printf("i : %d => doublon\n", i);
	    nbre_doublon++;
	}
    }
    return nbre_doublon;
}


void visuGrille(char grille[NBRE_LIGNE][NBRE_COL]){
    char i = 0, j =0, k = 0, l = 0;
    for(i=0; i<NBRE_BLOC; i = i+3){
	for(j=0; j<TAILLE_BLOC/3; j++){
	    for(k=0; k<NBRE_BLOC/3; k++){
		for(l=0; l<TAILLE_BLOC/3; l++){
		    printf("%d ", grille[i+j][k*3+l]);
		}
		printf("  ");
	    }
	    printf("\n");
	}
	printf("\n");
    }
}

void initBlocs(S_liste blocs[NBRE_BLOC]){
    char i = 0;
    for(i=0; i<NBRE_BLOC; i++){
	blocs[i] = creerListe();
    }
}

