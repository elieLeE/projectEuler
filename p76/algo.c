#include "algo.h"

int nAlreadyDone(int tab[], int n){
    int i = 0;
    while(tab[i]!=-1){
	if(tab[i] == n){
	    return i;
	}
	i++;
    }
    return -1;
}

void remplissageTabDone(int nDone[], int nAc[], int compt){
    int i = 0;
    while(nAc[i]!=-1){
	nDone[nAc[i]] = compt;
	compt--;
	i++;
    }
}

