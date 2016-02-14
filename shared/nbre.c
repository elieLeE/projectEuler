#include "nbre.h"

bool isPrime(unsigned int n){
    int i, carre;
    if(n%2==0){
	return false;
    }
    i = 3;
    while(i*i<=n){
	if(n%i == 0){
	    return false;
	}
    }
    return true;
}
