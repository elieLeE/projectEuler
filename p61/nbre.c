#include "nbre.h"

bool nextNbre(bool tab[5], int *ind, l_tabhach tabHach[5][100], unsigned char n){
    int i = 0, deb;
    if(*ind < 0){
	deb = 0;
    }
    else{
	deb = *ind;
    }
    for(i=deb; (i<5) & (tab[i] || tabHachEmpty((tabHach[i][n]).deb)); i++);

    if(i<5){
	if(*ind >= 0){
	    tab[*ind] = false;
	}
	tab[i] = true;
	*ind = i;
	return true;
    }
    else{
	return false;
    }
}
	 
bool dernierNbre(l_tabhach tabHach[5][100], unsigned char left, unsigned char right, bool tab[5], int *ind){
    unsigned char i = 0;
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
