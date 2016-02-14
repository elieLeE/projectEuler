#include "nbre.h"

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
