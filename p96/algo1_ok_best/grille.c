#include "grille.h"

void allocGrille(char ***grille){
    char i = 0;
    *grille = (char**)calloc(NBRE_LIGNE, sizeof(char*));
    for(i=0; i<NBRE_LIGNE; i++){
	(*grille)[i] = (char*)calloc(NBRE_COL, sizeof(char));
    }
}

void liberationGrille(char ***grille){
    char i = 0;
    for(i=0; i<NBRE_LIGNE; i++){
	free((*grille)[i]);
    }
    free(*grille);
}

void visuGrille(char **grille){
    char i = 0, j =0, k = 0, l = 0;
    for(i=0; i<NBRE_LIGNE; i = i+3){
	for(j=0; j<NBRE_LIGNE/3; j++){
	    for(k=0; k<NBRE_COL/3; k++){
		for(l=0; l<NBRE_COL/3; l++){
		    printf("%d ", grille[i+j][k*3+l]);
		}
		printf("  ");
	    }
	    printf("\n");
	}
	printf("\n");
    }
}

int nbreDeValPoss(char **grille, S_elem *e, char ligne, char col){
    bool tab[10] = {false};
    char i = 0, nbre_poss = 0;
    searchElemImpLigne(grille[ligne], tab, &(e->l_elem_imp), col);
    searchElemImpCol(grille, tab, &(e->l_elem_imp), ligne, col);
    searchElemImpBloc(grille, tab, &(e->l_elem_imp), ligne, col);
    for(i=9; i>0; i--){	//on commence par 9 => comme ca, la liste des val possibles sera triée dans l'ordre croissant
	if(!tab[i]){
	    nbre_poss++;
	    ajoutElemValPoss(&(e->l_val_poss), i);
	}
    }
    return nbre_poss;
}

void searchElemImpLigne(char *grille, bool *tab, liste_elem_imp *l_elem_imp, char col){
    char j = 0;
    for(j=0; j<NBRE_COL; j++){
	if(j != col){
	    if(grille[j] == 0){
		ajoutElemElemImp(l_elem_imp, &grille[j]);
	    }
	    else{
		tab[grille[j]] = true;
	    }
	}
    }
}


void searchElemImpCol(char **grille, bool *tab, liste_elem_imp *l_elem_imp, char ligne, char col){
    char i = 0;
    for(i=0; i<NBRE_COL; i++){
	if(i != ligne){
	    if(grille[i][col] == 0){
		ajoutElemElemImp(l_elem_imp, &grille[i][col]);
	    }
	    else{
		tab[grille[i][col]] = true;
	    }
	}
    }
}


void searchElemImpBloc(char **grille, bool *tab, liste_elem_imp *l_elem_imp, char ligne, char col){
    char debut_l = (ligne/3)*3, fin_l = debut_l+3;
    char debut_c = (col/3)*3, fin_c = debut_c+3;
    char i = 0, j = 0;
    for(i=debut_l; i<fin_l; i++){
	for(j=debut_c; j<fin_c; j++){
	    if(i != ligne && j != col){
		if(grille[i][j] == 0){
		    ajoutElemElemImp(l_elem_imp, &grille[i][j]);
		}
		else{
		    tab[grille[i][j]] = true;
		}
	    }
	}
    }
}

bool verificationReponse(char **grille){
    return verifLigne(grille) && verifCol(grille) && verifBlocs(grille);
}

void reInitTab(char *tab, char taille){
    char i = 0;
    for(i=0; i<taille; i++){
	tab[i] = 0;
    }
}

bool verifLigne(char **grille){
    char i = 0, j = 0, lim = 1;
    char tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0; i<NBRE_LIGNE; i++){
	lim++;
	for(j=0; j<NBRE_COL; j++){
	    if((tab[grille[i][j]]++) > lim){
		return false;
	    }
	}
    }
    return true;
}

bool verifCol(char **grille){
    char i = 0, j = 0, lim = 1;
    char tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0; i<NBRE_COL; i++){
	lim++;
	for(j=0; j<NBRE_LIGNE; j++){
	    if((tab[grille[j][i]]++) > lim){
		return false;
	    }
	}
    }
    return true;
}

bool verifBlocs(char **grille){
    char i = 0, j =0, k = 0, l = 0, lim = 1;
    char tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0; i<NBRE_LIGNE; i = i+3){
	for(j=0; j<NBRE_COL; j=j+3){
	    lim++;
	    for(k=i; k<i+3; k++){
		for(l=j; l<j+3; l++){
		    if((tab[grille[k][l]]++)>lim){
			return false;
		    }
		}
	    }
	}
    }
    return true;
}

