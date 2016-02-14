#include "tab.h"

void echange(int *a, int *b){
#if ECHANGE_GEN
    echangeGenerique((void*)a, (void*)b, sizeof(int));
#else
    int c = *a;
    *a = *b;
    *b = c;
#endif
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
