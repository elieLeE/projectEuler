#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../shared/alloc.h"
#include "pgcd.h"
#include <math.h>

#define LIMITE 1500000

int main(void){
    unsigned long a, b, c, p;
    unsigned long a2, b2, c2, p2;
    unsigned long limite = 1500000;
    unsigned long i, j;
    unsigned int *tab = my_calloc((limite+1)*sizeof(unsigned int));
    unsigned int compt = 0;

    for(i=1; i<LIMITE; i++){
	if(i==j){
	    break;
	}
	for(j=i+1; j<=LIMITE; j++){
	    a = j*j - i*i;
	    b = 2*i*j;
	    c = i*i + j*j;
	    if(pgcd(a, b) == 1){
		p = a + b + c;
		a2 = a;
		b2 = b;
		c2 = c;
		p2 = p;
		if(p>LIMITE){
		    break;
		}
		do{
		    tab[p2]++;
		    a2 = a2 + a;
		    b2 = b2 + b;
		    c2 = c2 + c;
		    p2 = a2 + b2 + c2;
		}while(p2<=LIMITE);
	    }
	}
    }

    for(i=0; i<=limite; i++){
	if(tab[i] == 1){
	    compt++;
	}
    }
    printf("%d\n", compt);

    return 0;
}

