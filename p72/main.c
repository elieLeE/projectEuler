#include <stdio.h>
#include <stdlib.h>
#include "nbre.h"
#include "liste.h"

#define LIMITE_Y (int)1000000
#define TAILLE_TAB nbreNbrePrime(LIMITE_Y)

/**
 * algo correcte et assez rapide pour peu de nombre mais quand limite_y trop grand => les tableaux sont trop grands => deviznt très lent.
 * */

int main(){
    long compt = 1;
    long phi_y;
    int i = 0;
    liste l;
    remplissageListe(&l);
    liste p = l;

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
