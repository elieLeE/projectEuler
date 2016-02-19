#include "grille.h"

void visuGrille(char grille[NBRE_LIGNE][NBRE_COL]){
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

int nbreDeValPoss(char grille[NBRE_LIGNE][NBRE_COL], S_elem *e, char ligne, char col){
    bool tab[10] = {false};
    char i = 0, nbre_poss = 0;
    searchElemImpLigne(grille[ligne], tab, &(e->l_elem_imp), ligne, col);
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

void searchElemImpLigne(char grille[NBRE_COL], bool tab[10], liste_elem_imp *l_elem_imp, char lig, char col){
    char j = 0;
    S_pos pos;
    pos.lig = lig;
    for(j=0; j<NBRE_COL; j++){
	if(j != col){
	    if(grille[j] == 0){
		pos.col = j;
		ajoutElemElemImp(l_elem_imp, &grille[j], pos);
	    }
	    else{
		tab[grille[j]] = true;
	    }
	}
    }
}


void searchElemImpCol(char grille[NBRE_LIGNE][NBRE_COL], bool tab[10], liste_elem_imp *l_elem_imp, char ligne, char col){
    char i = 0;
    S_pos pos;
    pos.col = col;
    for(i=0; i<NBRE_COL; i++){
	if(i != ligne){
	    if(grille[i][col] == 0){
		pos.lig = i;
		ajoutElemElemImp(l_elem_imp, &grille[i][col], pos);
	    }
	    else{
		tab[grille[i][col]] = true;
	    }
	}
    }
}


void searchElemImpBloc(char grille[NBRE_LIGNE][NBRE_COL], bool tab[9], liste_elem_imp *l_elem_imp, char ligne, char col){
    char debut_l = (ligne/3)*3, fin_l = debut_l+3;
    char debut_c = (col/3)*3, fin_c = debut_c+3;
    char i = 0, j = 0;
    S_pos pos;
    for(i=debut_l; i<fin_l; i++){
	for(j=debut_c; j<fin_c; j++){
	    if(i != ligne && j != col){
		if(grille[i][j] == 0){
		    pos.lig = i;
		    pos.col = j;
		    ajoutElemElemImp(l_elem_imp, &grille[i][j], pos);
		}
		else{
		    tab[grille[i][j]] = true;
		}
	    }
	}
    }
}

bool verificationReponse(char grille[NBRE_LIGNE][NBRE_COL]){
    return verifLigne(grille) && verifCol(grille) && verifBlocs(grille);
}

void reInitTab(char tab[10], char taille){
    char i = 0;
    for(i=0; i<taille; i++){
	tab[i] = 0;
    }
}

bool verifLigne(char grille[NBRE_LIGNE][NBRE_COL]){
    int i = 0, j = 0;
    char tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0; i<NBRE_LIGNE; i++){
	for(j=0; j<NBRE_COL; j++){
	    if((tab[grille[i][j]]++) > 1){
		return false;
	    }
	}
	reInitTab(tab, 10);
    }
    return true;
}

bool verifCol(char grille[NBRE_LIGNE][NBRE_COL]){
    int i = 0, j = 0;
    char tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0; i<NBRE_COL; i++){
	for(j=0; j<NBRE_LIGNE; j++){
	    if((tab[grille[j][i]]++) > 1){
		return false;
	    }
	}
	reInitTab(tab, 10);
    }
    return true;
}

bool verifBlocs(char grille[NBRE_LIGNE][NBRE_COL]){
    char i = 0, j =0, k = 0, l = 0;
    char tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0; i<NBRE_LIGNE; i = i+3){
	for(j=0; j<NBRE_COL; j=j+3){
	    for(k=i; k<i+3; k++){
		for(l=j; l<j+3; l++){
		    if((tab[grille[k][l]]++)>1){
			return false;
		    }
		}
	    }
	    reInitTab(tab, 10);
	}
    }
    return true;
}

