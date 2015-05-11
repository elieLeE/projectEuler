#include "tab.h"

bool next_nbre(char tab[]){
    int i = 0;
    while(tab[i] == 9){
	tab[i] = 0;
	i++;
    }
    if(i>6){
	return false;
    }
    tab[i]++;
    return true;
}

void aff_nbre(char tab[]){
    int i = 0;
    for(i=6; i>=0; i--){
	printf("%d", tab[i]);
    }
    printf("\n");
}
