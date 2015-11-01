#include "tab.h"

void initTab(int *tab){
    int i = 0;
    for(i=0; i<NBRE_DIGIT; i++){
	tab[i] = i+1;
    }
}

long tabToNbre(int *tab){
    int i = 0;
    long sum = 0, mul = 1;
    //visuTab(tab);
    for(i=9; i>=0; i--){
	sum = sum + tab[i]*mul;
	mul*=10;
    }
    return sum;
}

void echange(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void copieTab(int *dest, int *src, int ind){
    int i = 0;
    for(i=ind; i<NBRE_DIGIT; i++){
	dest[i] = src[i];
    }
}

void visuTab(int *tab){
    int i = 0;
    for(i=0; i<NBRE_DIGIT; i++){
	printf("%d, ", tab[i]);
    }
    printf("\n");
}
