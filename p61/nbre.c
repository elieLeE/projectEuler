#include "nbre.h"

bool nextNbre(bool tab[5], char *ind, l_tabhach tabHach[5][100], char n){
    char i = 0, deb;
    if(*ind < 0){
	deb = 0;
    }
    else{
	deb = *ind;
    }
    for(i=deb; i<5 & (tab[i] || tabHachEmpty(tabHach[i][n])); i++);

    if(i<5){
	tab[*ind] = false;
	tab[i] = true;
	*ind = i;
	return true;
    }
    else{
	return false;
    }
}
	 
bool dernierNbre(l_tabhach tabHach[5][100], char left, char right, bool tab[5], char *ind){
    char i = 0;
    for(i=0; i<5; i++){
	if(!tab[i]){
	    break;
	}
    }
    *ind = i;
    c_tabhach p = tabHach[i][right].deb;
    while(!tabHachEmpty(p)){
	if(p->right == left){
	    return true;
	}
	p = p->suiv;
    }
    return false;
}
