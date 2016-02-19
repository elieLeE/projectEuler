#include "nbre.h"
#include "../shared/nbre.h"

int main(){
    unsigned int i = 0;
    unsigned int tabPrime[TAILLE_TAB] = {0};
    remplissageTabPrime(tabPrime);

#if ALGO_FAST
    unsigned int n = 2;
    i = 0;
    while(n * tabPrime[i] < LIMITE){
	n = n * tabPrime[i];
	i++;
    }
    printf("%d\n", n);

#else
    double phi_max = 0;
    int nbre_phi_max;
    double calcul;

    for(i=6; i<=LIMITE; i+=4){
	calcul = phi(i, tabPrime);
	if(calcul > phi_max){
	    phi_max = calcul;
	    nbre_phi_max = i;
	}
    }
    printf("phi max : %f, pour le nombre : %d\n", phi_max, nbre_phi_max);
#endif

    return 0;
}
