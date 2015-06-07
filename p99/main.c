#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include <gmp.h>

#define NBRE_LIGNE 1000

int main(){
    FILE* fichier = NULL;
    duo d_cour, d_max;
    int i = 0;
    int diff;
    double div;

    

    fichier = ouvFichier("p099_base_exp.txt", "r+");
    if(fichier == NULL){
        printf("fichier non trouvé\n");
        exit(0);
    }
    nextDuo(fichier, &d_max);
    while(i!=NBRE_LIGNE){
    	nextDuo(fichier, &d_cour);
	if(d_max.nbre > d_cour.nbre){
	    if(d_max.exp > d_cour.exp){
		printf("cas 1 => on ne fait rien\n");
	    }
	    else{
		diff = d_max.exp - d_cour.exp;
		div = (1.0*d_max.nbre)/d_cour.nbre;
		mpf_ui_pow
		printf("cas 2\n");
	    }
	}
	else{
	    if(d_max.exp > d_cour.exp){
		printf("cas 3\n");
	    }
	    else{
		printf("cas 4\n");
		d_max = d_cour;
	    }
	}
    	printf("i : %d, nbre : %d, exp : %d\n", i, d_cour.nbre, d_cour.exp);
    	i++;
    }

    fermerFichier(fichier);
    return 0;
}
