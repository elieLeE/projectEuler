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

char nbreDigit(short nbre){
    char nbreDigit = 0;
    while(nbre>=1){
	nbre /= 10;
	nbreDigit++;
    }
    return nbreDigit;
}

int transElementToNbre(short nbre, char nbreDigit){
    char i = 0;
    int n = (int)nbre;
    for(i=0; i<nbreDigit; i++){
	n *= 10;
    }
    return n;
}

bool isPerm(element e1, element e2){
    int nbre = transElementToNbre(e1.nbre, e2.nbreDigit)+e2.nbre;
    if(isPrime(nbre)){
	nbre = transElementToNbre(e2.nbre, e1.nbreDigit)+e1.nbre;
	if(isPrime(nbre)){
	    return true;
	}
    }
    return false;
}

bool isPermTab(element e, element tab[], char nbreEval){
    char i = 0;
    for(i=0; i<nbreEval; i++){
	if(!isPerm(e, tab[i])){
	    return false;
	}
    }
    return true;
}









