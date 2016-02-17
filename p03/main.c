#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../shared/nbre.h"

#define NBRE 600851475143

bool primeDiv(unsigned long div){
    return ((NBRE%div == 0) && (isPrime(NBRE/div)));
}

int main(){
    unsigned long div = 3, maxDiv = 0, otherDiv;
    unsigned long rac = (unsigned long)sqrt(NBRE);

    while(div<=rac){
	if(NBRE%div==0){
	    if((maxDiv < div) && isPrime(div)){
		maxDiv = div;
	    }
	    else{
		otherDiv = NBRE/div;
		if((maxDiv < otherDiv) && isPrime(otherDiv)){
		    maxDiv = otherDiv;
		}
	    }
	}
	div = div + 2;
    }

    printf("%ld\n", maxDiv);

    return 0;
}

