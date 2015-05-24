#include <stdio.h>
#include <stdlib.h>
#include "nbre.h"
#include "liste.h"

#define LIMITE_Y (int)1000000
#define TAILLE_TAB nbreNbrePrime(LIMITE_Y)

/**
 * algo correcte et assez rapide pour peu de nombre mais quand limite_y trop grand => les tableaux sont trop grands => deviznt très lent.
 * */

bool frac_irreduc(int y, int x){
    int r = y%x;
    while(r != 0){
	y = x;
	x = r;
	r = y%x;
    }
    //printf("pgcd(%d, %d) = %d\n", x, y, x);
    return (x == 1);
}

int main(){
    int y = 2, tab_pos = 0; 	    
    long compt = 1;
    int compt_aff = 0;
    long phi_y;
    int i = 0;
    liste l;
    remplissageListe(&l);
    //visuListe(l);
    liste p = l;
    char c;

    for(i=3; i<=LIMITE_Y; i++){
	if(p->suiv!=NULL && i == p->suiv->nbre){
	    p = p->suiv;
	    compt += p->nbre-1;
	}
	else{
	    compt += phiListe(i, p->nbre, l);
	}
    }

    printf("compt : %ld\n", compt);
    return 0;
}
