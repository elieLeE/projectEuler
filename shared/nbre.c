#include "nbre.h"

int min(unsigned int a, unsigned int b){
    if(a < b){
	return a;
    }
    return b;
}

int max(unsigned int a, unsigned int b){
    if(a > b){
	return a;
    }
    return b;
}

bool isPrime(unsigned long n){
    unsigned long i;
    if(n%2==0){
	return false;
    }
    i = 3;
    while(i*i<=n){
	if(n%i == 0){
	    return false;
	}
	i = i+2;
    }
    return true;
}

int nbreDigits(int n){
    int i = 1;
    int compt = 0;
    while(n>=i){
	i = i*10;
	compt++;
    }
    return compt;
}
