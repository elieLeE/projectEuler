#include "algo2.h"

#define REPETION 10

char numBlocMaxDoublon(char grille[NBRE_LIGNE][NBRE_COL]){
    short nbre_doublon_col[NBRE_BLOC] = {0};
    short nbre_doublon_ligne[NBRE_BLOC] = {0};
    short nbre_doublon[NBRE_BLOC] = {0};

    char i = 0;
    char bloc_second_choix = -1, bloc_max_doublon = -1;
    short max = 0, sum = 0;
    char var_tmp = 0;

    static char derniers_blocs_choisis = -1;
    static int compteur = 0;
    static char second_choix = -1;

    //les lignes
    for(i=0; i<NBRE_LIGNE; i = i+3){
	nbre_doublon_ligne[i] += nbreDoublonLigne(grille[i]);
	nbre_doublon_ligne[i] += nbreDoublonLigne(grille[i+1]);
	nbre_doublon_ligne[i] += nbreDoublonLigne(grille[i+2]);
	nbre_doublon_ligne[i+1] = nbre_doublon_ligne[i];
	nbre_doublon_ligne[i+2] = nbre_doublon_ligne[i];
    }

    for(i=0; i<NBRE_COL/3; i++){
	nbre_doublon_col[i] += nbreDoublonCol(grille, i*3);
	nbre_doublon_col[i] += nbreDoublonCol(grille, i*3+1);
	nbre_doublon_col[i] += nbreDoublonCol(grille, i*3+2);
	nbre_doublon_col[i+3] = nbre_doublon_col[i];
	nbre_doublon_col[i+6] = nbre_doublon_col[i];
    }

    for(i=0; i<NBRE_BLOC; i++){
	var_tmp = nbre_doublon_ligne[i] + nbre_doublon_col[i];
	sum += nbre_doublon_ligne[i] + nbre_doublon_col[i];
	if(var_tmp > max){
	    second_choix = max;
	    bloc_second_choix = bloc_max_doublon;
	    max = var_tmp;
	    bloc_max_doublon = i;
	}
	else if(var_tmp > second_choix){
	    second_choix = var_tmp;
	    bloc_second_choix = i;
	}
    }
    //printf("somme des doublons : %d, derniers_blocs_choisis : %d, bloc_max_doublon : %d, bloc_second_choix : %d\n", sum, derniers_blocs_choisis, bloc_max_doublon, bloc_second_choix);
    if(bloc_max_doublon == derniers_blocs_choisis){
	compteur++;
	if(compteur > REPETION){
	    compteur = 0;
	    derniers_blocs_choisis = second_choix;
	    return bloc_second_choix;
	}
	else{
	    return bloc_max_doublon;
	}
    }
    else{
	derniers_blocs_choisis = bloc_max_doublon;
	compteur = 1;
	return bloc_max_doublon;
    }

    //printf("bloc_max_doublon : %d\n", bloc_max_doublon);
}

void remplissageAleatoireBloc(S_liste bloc){
    S_liste p = bloc; 
    while(!estVide(p)){
	*(p->val) = rand()%(9-1)+1;
	p = p->suiv;
    }
}

void premierRemplissageBlocs(S_liste blocs[NBRE_BLOC]){
    char i = 0;
    for(i=0; i<NBRE_BLOC; i++){
	remplissageAleatoireBloc(blocs[i]);
    }
}


