#include "tab.h"

int recherche_boucle(int tab[], int taille_max){
    int i = 0, result;
    for(i=taille_max-2; i>=0; i--){
	if(tab[taille_max-1] == tab[i]){
	    return (taille_max - 1 - i);
	}
    }
    return -1;    
}

int recherche_min_tab(int tab[], int indice_min, int indice_max){
    int i = 0, min = 1000001;
    for(i=indice_min; i<indice_max; i++){
	if(tab[i]<min){
	    min = tab[i];
	}
    }
    return min;
}

void aff_tab(int tab[], int taille_max){
    printf("affichage du tableau\n");
    int i = 0;
    for(i=0; i<taille_max-1; i++){
	/*if(tab[i] == 12496){
	    printf("ICI !!!!!!!\n");
	    exit(1);
	}*/
	printf("%d, ", tab[i]);
    }
    printf("%d\n", tab[i]);
}
