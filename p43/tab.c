#include "tab.h"

long tabToNbre(unsigned int *tab){
    int i = 0;
    unsigned long sum = 0, mul = 1;
    for(i=9; i>=0; i--){
	sum = sum + tab[i]*mul;
	mul*=10;
    }
    return sum;
}

void echange(unsigned int *a, unsigned int *b){
    bool x = false;
    if(x){
	echangeGenerique((void*)a, (void*)b, sizeof(unsigned int));
    }
    else{
	unsigned int c = *a;
	*a = *b;
	*b = c;
    }
}

void copieTab(unsigned int *dest, unsigned int *src, unsigned int ind){
    unsigned int i = 0;
    for(i=ind; i<10; i++){
	dest[i] = src[i];
    }
}

void visuTab(unsigned int *tab){
    unsigned int i = 0;
    for(i=0; i<10; i++){
	printf("%d", tab[i]);
    }
    printf("\n");
}
