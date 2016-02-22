#include "nbre.h"

void remplissageTabPrime(unsigned int* tabPrime){
    unsigned int i, j;
    tabPrime[0] = 2;
    j = 1;
    for(i=3; j<TAILLE_TAB_PRIME; i = i+2){
	if(isPrime(i)){
	    tabPrime[j] = i;
	    j++;
	}
    }
}

void visuElem(void* elem){
    printf("%d, ", *((unsigned int*)elem));
}

int comparElement(void *a, void *b){
    unsigned int ia = *((unsigned int*)a);
    unsigned int ib = *((unsigned int*)b);
    if(ia > ib){
	return 1;
    }
    if(ia == ib){
	return 0;
    }
    return -1;
}

unsigned int nbreAdd(unsigned int n, unsigned int m, unsigned int* tabPrime){
    unsigned int compt = 0;
    unsigned int valSearch;
    int i;
    valSearch = min(n, (m==0)? n: m);
    int deb = searchInd(tabPrime, TAILLE_TAB_PRIME, sizeof(unsigned int), &valSearch, (int(*)(void*, void*))comparElement);
    if(deb != -1){
	if(tabPrime[deb] == n){
	    compt = 1;
	}
	for(i=0; i<=deb; i++){
	    compt = compt + nbreAdd(n - tabPrime[i], tabPrime[i], tabPrime);
	}
    }
    return compt;
}
