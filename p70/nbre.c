#include "nbre.h"

bool nbrePrime(int nbre){
    int i = 0;
    if(nbre%2==0)
	return false;
    for(i=3; i*i<=nbre; i = i+2){
	if(nbre%i == 0){
	    return false;
	}
    }
    return true;
}

double phi(int nbre, int tab[]){
    int i=0, debut = 0;
    double num = nbre*1.0, denom = 1.0;
    double tmp;
    if(indiceFirstDiviseur(nbre, &debut, tab)){
	num = num*(tab[debut]-1);
	denom *= tab[debut];
	for(i=debut+1; i*tab[debut]<=nbre & i<TAILLE_TAB; i++){
	    if(nbre%tab[i] == 0){
		num = num*(tab[i]-1);
		denom *= tab[i];
	    }
	}
    }
    return num/denom;
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
    int i = 0, j = 1;
    tab[0] = 2;
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

bool permutation(int n, int phiN){
    static int tabDigitN[10], tabDigitPhiN[10];
    nbreToDigits(tabDigitN, n);
    nbreToDigits(tabDigitPhiN, phiN);
    int i;
    for(i=0; i<10; i++){
	if(tabDigitN[i] != tabDigitPhiN[i]){
	    return false;
	}
    }
    return true;
}

void reInitTab(int *tab){
    int i = 0;
    for(i=0; i<10; i++){
	tab[i] = 0;
    }
}

void nbreToDigits(int *tab, int n){
    reInitTab(tab);
    int n2;
    while(n>0){
	n2 = n/10;
	n = n - n2*10;
	tab[n]++;
	n = n2;
    }
}
