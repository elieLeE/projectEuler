#include <stdio.h>
#include <stdlib.h>
#include "racine.h"

#define LIMITE 100

int main(){
    int i;
    int diffCarre = 3;
    int nextCarre = 1;
    unsigned int sum = 0;

    for(i=1; i<LIMITE; i++){
	if(i == nextCarre){
	    nextCarre = nextCarre + diffCarre;
	    diffCarre = diffCarre + 2;
	}
	else{
	    //sum = sum + sum100DecimalDigits(i);
	}
    }

    i = 2;
    printf("%d => %d\n\n", i, sum100DecimalDigits(i));

    int n = 7, deb = 1, res;
    printf("nbreSoustraction(%d) => %d, ", n, nbreSoustraction(n, &deb, &res));
    printf("deb => %d, res => %d\n\n", deb, res);

    n = 312;
    deb = 41;
    printf("nbreSoustraction(%d) => %d, ", n, nbreSoustraction(n, &deb, &res));
    printf("deb => %d, res => %d\n", deb, res);

    printf("%d\n", sum);
	    
    return 0;
}

