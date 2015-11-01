#include "tab.h"

void echange(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void copieTab(int *dest, int *src, int ind){
    int i = 0;
    for(i=ind; i<10; i++){
	dest[i] = src[i];
    }
}

void visuTab(int *tab){
    int i = 0;
    for(i=0; i<10; i++){
	printf("%d", tab[i]);
    }
    printf("\n");
}
