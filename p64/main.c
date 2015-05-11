#include "calcul_fraction.h"
#include <stdbool.h>

#define LIMITE 10000
#define TAILLE_TAB 7

bool dans_tab(int nbre, int tab[]){
    int i = 0; 
    for(i=0; i<TAILLE_TAB; i++){
	if(nbre == tab[i]){
	    return false;
	}
    }
    return true;
}

int main(){
    int compt = 0, i;

    for(i=2; i<=LIMITE; i++){
	if(calcul_periode(i)%2 != 0){
	    compt++;
	}
    }
    printf("compteur : %d\n", compt);

    return 0;
}
