#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "fichier.h"
#include <math.h>

#define NBRE_LIGNE 1000

bool courSupMax(duo *max, duo *cour){
#if MODE
    if(mpz_cmp(cour->nbre, max->nbre)>0){
#else 
    if(cour->nbre > max->nbre){
#endif
	return true;
    }
    return false;
}

void calculNbre(duo *cour){
#if MODE
	mpz_init(cour->nbre);
	mpz_add_ui(cour->nbre, cour->nbre, cour->a);
	mpz_pow_ui(cour->nbre, cour->nbre, cour->b);
#else
	cour->nbre = 0.0;
	cour->nbre = log(cour->a);
	cour->nbre = cour->b * cour->nbre;
#endif
}

int main(){
    FILE* fichier = NULL;
    int i =0;
    duo cour, max;
#if MODE
    mpz_init(max.nbre);
    mpz_add_ui(max.nbre, max.nbre, 0);
#else
    max.nbre = 0.0;
#endif

    fichier = ouvFichier("p099_base_exp.txt", "r+");
    if(fichier == NULL){
        printf("fichier non trouvé\n");
        exit(0);
    }
    while(i!=NBRE_LIGNE){
    	nextDuo(fichier, &cour);
	calculNbre(&cour);
	cour.lig = i;
	if(courSupMax(&max, &cour)){
	    max = cour;
	}
    	i++;
    }
    printf("%d\n", max.lig+1);
    fermerFichier(fichier);
    return 0;
}
