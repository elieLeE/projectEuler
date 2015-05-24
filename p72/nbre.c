#include "nbre.h"

bool isPrime(int nbre){
    int i = 0;
    for(i=3; i*i<=nbre; i = i+2){
	if(nbre%i == 0){
	    return false;
	}
    }
    return true;
}

liste searchDeb(int n, liste l){
    liste p = l;
    while(p!=NULL && p->nbre<=n && n%(p->nbre)!=0){
	p=p->suiv;
    }
    return p;
}

long phiListe(int n, int maxPrime, liste l){
    liste p = searchDeb(n, l);
    int deb = p->nbre;
    long end = n/deb;
    long num = n*(deb-1);
    int denom = deb;

    p = p->suiv;
    while(p!=NULL){
	if(p->nbre>end){
	    break;
	}
	else{
	    if(n%(p->nbre)==0){
		num *= p->nbre-1;
		denom *= p->nbre;
	    }
	}
	p = p->suiv;
    }
    return num/denom;
}
