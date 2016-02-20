#include "nbre.h"

void visuTab(unsigned int *tab, unsigned int nbrePrime){
    unsigned int i;
    for(i=0; (i<nbrePrime) && (tab[i] != 0); i++){
	printf("%d, ", tab[i]);
    }
    printf("\b\b \n");
}

void remplissageTabDiviseur(unsigned int* tabDiv, unsigned int *nbreDiv, unsigned int n){
    unsigned int i, j = 0;
    *nbreDiv = 0;
    for(i=2; i*2<=n; i++){
	if(n%i == 0){
	    tabDiv[j] = i;
	    j++;
	}
    }
    *nbreDiv = j;
}

bool abPrime(unsigned int n, unsigned int* tabDiv, unsigned int nbreDiv){
    unsigned int i;
    for(i=0; (tabDiv[i]<=n) && (i<nbreDiv); i++){
	if(n%tabDiv[i] == 0){
	    return false;
	}
    }
    return true;
}

unsigned int nbreFracIrr(unsigned int denom){
    unsigned int compt = 0;
    unsigned int maxA = denom/DENOM_MIN;
    unsigned int minA = denom/DENOM_MAX + 1;
    unsigned int a;
    if(isPrime(denom)){
	return maxA - minA + 1;
    }
    else{
	a = maxA;
	static unsigned int tabDiv[LIMITE];
	unsigned int nbreDiv;
	remplissageTabDiviseur(tabDiv, &nbreDiv, denom);
	for(a=maxA; a>=minA; a--){
	    if(abPrime(a, tabDiv, nbreDiv)){
		compt++;
	    }
	}
	return compt;
    }
}

