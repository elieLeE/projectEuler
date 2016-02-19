#include <stdio.h>
#include <stdlib.h>
#include "racine.h"

#define LIMITE 100

int main(){
    unsigned int i;
    unsigned int diffCarre = 3;
    unsigned int nextCarre = 1;
    unsigned int sum = 0;

    for(i=1; i<LIMITE; i++){
	if(i == nextCarre){
	    nextCarre = nextCarre + diffCarre;
	    diffCarre = diffCarre + 2;
	}
	else{
	    sum = sum + sum100DecimalDigits(i);
	}
    }

    printf("%d\n", sum);
	    
    return 0;
}

