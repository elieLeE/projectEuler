#include "nbre.h"

double phi(unsigned int nbre, unsigned int tab[]){
    unsigned int i=0, debut = 0;
    double produit = 2.0;
    double tmp;
    if(indiceFirstDiviseur(nbre, &debut, tab)){
	tmp = (1.0*tab[debut])/(tab[debut]-1);
	produit = produit*tmp;
	for(i=debut+1; (i*tab[debut]<=nbre) & (i<TAILLE_TAB); i++){
	    if(nbre%tab[i] == 0){
		tmp = (tab[i]*1.0)/(tab[i]-1);
		produit = produit*tmp;
	    }
	}
    }
    return produit;
}

bool indiceFirstDiviseur(unsigned int nbre, unsigned int *indice, unsigned int tab[]){
    unsigned int i = 0;
    while(tab[i] <= nbre){
	if(nbre%tab[i] == 0){
	    *indice = i;
	    return true;
	}
	i++;
    }
    return false;
}

unsigned int nextPrime(unsigned int deb){
    while(!isPrime(deb)){
	deb = deb + 2;
    }
    return deb;
}

void remplissageTabPrime(unsigned int tab[]){
    unsigned int i, deb = 3;
    for(i=0; i<TAILLE_TAB; i++){
	tab[i] = nextPrime(deb);
	deb = tab[i]+2;
    }
}

unsigned int nbreNbrePrime(unsigned int limite){
    unsigned int i =0, compt = 1;
    for(i=3; i<limite; i+=2){
	if(isPrime(i)){
	    compt++;
	}
    }
    return compt;
}

