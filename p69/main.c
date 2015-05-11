#include "nbre.h"

#define LIMITE 1000000

int main(){
    int i = 0;
    int tabPrime[TAILLE_TAB] = {0};
    double phi_max = 0.0;
    int nbre_phi_max;
    remplissageTabPrime(tabPrime);

    double calcul;
    for(i=6; i<=LIMITE; i+=4){
		calcul = phi(i, tabPrime);
		if(calcul > phi_max){
			phi_max = calcul;
			nbre_phi_max = i;
		}
    }
    printf("phi max : %f, pour le nombre : %d\n", phi_max, nbre_phi_max);

    return 0;
}
