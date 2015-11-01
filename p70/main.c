#include "nbre.h"


int main(){
    int i = 0;
    int tabPrime[TAILLE_TAB] = {0};
    double phi_min = 2.0, phiI, div;
    int nbre_phi_min;
    int compt = 0;

    remplissageTabPrime(tabPrime);
    /*printf("phi(8) => %lf\n", phi(8, tabPrime));
    printf("phi(87109) => %lf\n", phi(87109, tabPrime));*/

    for(i=6; i<=LIMITE; i++){
	phiI = phi(i, tabPrime);
	if(compt == 100000){
	    compt = 0;
	    printf("%d\n", i);
	}
	compt++;
	if(permutation(i, phiI)){
	    div = i/phiI;
	    if(div < phi_min){
		phi_min = div;
		nbre_phi_min = i;
	    }
	}
    }
    printf("phi min : %f, pour le nombre : %d\n", phi_min, nbre_phi_min);

    return 0;
}
