#include "nbre.h"

int nextNbrePrime(int prime){
    int i = prime +2;
    while(!nbrePrime(i)){
	i = i +2;
    }
    return i;
}

bool nbrePrime(int nbre){
    int i = 0;
    for(i=3; i*i<=nbre; i = i+2){
	if(nbre%i == 0){
	    return false;
	}
    }
    return true;
}
