#include <stdio.h>
#include <stdlib.h>
#include "nbre.h"
#include "liste.h"

#define LIMITE_Y (int)8
#define TAILLE_TAB nbreNbrePrime(LIMITE_Y)

/**
 * algo correcte et assez rapide pour peu de nombre mais quand	limite_y trop grand => les tableaux sont trop grands => deviznt très lent.
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
    int y = 2, compt = 0, tab_pos = 0; 	    
    int compt_aff = 0;
    int phi_y;
    int i = 0;
    liste l;
    remplissageListe(&l);
    visuListe(l);
    liste p = l;

    while(p!=NULL){
	printf("mul-p->nbre : %d\n", p->nbre);
	//phi_y = phi2(LIMITE_Y, p->nbre, tab_prime);
	compt += phi_y;
	printf("mul-p->nbre : %d, phi : %d, compt : %d, i : %d\n", p->nbre, phi_y, compt, i);
	if(compt_aff == 1000){
	    printf("y : %d, phi : %d, compt : %d\n", y, phi_y, compt);
	    compt_aff = 0;
	}
	y++;
	p = p->suiv;
	compt_aff++;
    }

    printf("compt : %d\n", compt);
    return 0;
}





	//printf("fraction %d/%d => ", x, y);
	/*if(frac_irreduc(y, x)){
	    //printf("oui\n");
	    compt++;
	}
	/*else{
	    printf("non\n");
	}*/
	/*if(x+1 >= y){
	    //printf("changement de valeur pour y\n");
	    y_s++;
	    y = y_s;
	    y_pair = !y_pair;
	    if(!y_pair){
		compt++;
		//printf("2/%d oui d'office\n", y);
	    }
	    /*else{
		printf("2/%d non d'office\n", y);
	    }*/
	    /*x = 3;
	    compt++;
	    //printf("1/%d oui d'office\n", y);
	}
	else{
	    if(y_pair){
		x+=2;
	    }
	    else{
		x++;
	    }
	}
	//printf("fin du while, x : %d, y : %d\n", x, y);*/
