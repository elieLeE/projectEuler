#include "nbre.h"

bool nextNbre(bool tab[5], char *ind, l_tabhach tabHach[5][100], char n){
    printf("n : %d, *ind : %d\n", n, *ind);
    char i = 0;
    for(i=(*ind); i<5; i++){
	if((tab[i] || tabHachEmpty(tabHach[i][n]))){
	    if(tab[i]){
		printf("tab[%d] vrai\n", i);
	    }
	    if(tabHachEmpty(tabHach[i][n])){
		printf("tabHach[%d][%d] vide\n", i, n);
	    }
	    //printf("tabhach[%d][%d] vide ou occupe\n", i, n);
	}
	else{
	    //printf("tabhach[%d][%d] non vide\n", i, n);
	    break;
	}
    }

    if(i<5){
	tab[i] = true;
	*ind = i;
	return true;
    }
    else{
	*ind = 0;
	return false;
    }
}
	 
bool dernierNbre(l_tabhach tabHach[5][100], char left, char right, bool tab[5], char *ind){
    char i = 0;
    //printf("dernierNbre\n");
    for(i=0; i<5; i++){
	if(!tab[i]){
	    break;
	}
    }
    *ind = i;
    c_tabhach p = tabHach[i][right].deb;
    while(!tabHachEmpty(p)){
	if(p->right == left){
	    //printf("suite terminée\n");
	    return true;
	}
	p = p->suiv;
    }
    //printf("suite non terminée\n");
    return false;
}
