#include "nbre.h"

bool nbrePrime(int nbre){
    int i = 0;
    for(i=3; i*i<=nbre; i = i+2){
	if(nbre%i == 0){
	    return false;
	}
    }
    return true;
}

double phi(int nbre, int tab[]){
    int i=0, debut = 0;
    double produit = 2.0;
    double tmp;
    if(indiceFirstDiviseur(nbre, &debut, tab)){
	tmp = (1.0*tab[debut])/(tab[debut]-1);
	produit = produit*tmp;
	for(i=debut+1; i*tab[debut]<=nbre & i<TAILLE_TAB; i++){
	    if(nbre%tab[i] == 0){
		tmp = (tab[i]*1.0)/(tab[i]-1);
		produit = produit*tmp;
	    }
	}
    }
    return produit;
}

bool indiceFirstDiviseur(int nbre, int *indice, int tab[]){
    int i = 0;
    while(tab[i] <= nbre){
	if(nbre%tab[i] == 0){
	    *indice = i;
	    return true;
	}
	i++;
    }
    return false;
}

void remplissageTabPrime(int tab[]){
    int i = 0, j = 0;
    for(i=3; i<LIMITE; i+=2){
	if(nbrePrime(i)){
	    tab[j] = i;
	    j++;
	}
    }
}

int nbreNbrePrime(int limite){
    int i =0, compt = 1;
    for(i=3; i<limite; i+=2){
	if(nbrePrime(i)){
	    compt++;
	}
    }
    return compt;
}

