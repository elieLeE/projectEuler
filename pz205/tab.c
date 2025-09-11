#include "tab.h"

void remplissageTab(int tab[], int nbreDes, int max){
    int *des = (int*)calloc(nbreDes, sizeof(int));
    initDes(des, nbreDes);
    while(true){
	if(!nextConfig(des, nbreDes, max)){
            break;
        }
        else{
            tab[sumTab(des, nbreDes)]++;
        }
    }
    free(des);
}

int sumTab(int tab[], int nbreDes){
    int i =0, sum =0 ;
    for(i=0; i<nbreDes; i++){
        sum += tab[i];
    }
    return sum;
}

void affTab(char *name, int tab[], int taille){
    int i = 0;
    printf("%s : \n", name);
    for(i=0; i<taille; i++){
        printf("tab[%d] : %d\n", i, tab[i]);
    }
    printf("\n\n");
}
