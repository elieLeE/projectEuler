#include "proba.h"

bool nextConfig(int tab[], int nbreDes, int max){
    int i = nbreDes-1;
    while(i>=0 && tab[i] == max){
        i--;
    }
    if(i <0){
        return false;
    }
    tab[i]++;
    if(i<nbreDes-1){
        int j = 0;
        for(j=i+1; j<nbreDes; j++){
            tab[j] = 1;
        }
    }
    return true;
}

void initDes(int des[], int nbreDes){
    int i = 0;
    for(i=0; i<nbreDes; i++){
        des[i] = 1;
    }
    des[nbreDes-1] = 0;
}

double sumProba(int tab1[], int tab2[]){
    double sumTot = 0.0, sumInt;
    int i = 0;
    for(i=0; i<TAILLE_TAB; i++){
	if(tab1[i] != 0){
	    sumInt = sumTab(tab2, i);
	    sumTot += sumInt*tab1[i];
	}
    }
    return sumTot;
}
