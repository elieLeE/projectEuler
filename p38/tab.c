#include "tab.h"

void reInitTabB(bool *tab){
    int i = 0;
    for(i=1; i<10; i++)
        tab[i] = false;
}

bool remplissageTab(bool *tab, int n, int *nbreDigits){
    int n2 = n;
    while(n>0){
        n2 = n/10;
        n=n-n2*10;
	if(n==0 || tab[n]){
            return false;
        }
        tab[n] = true;
        n = n2;
        (*nbreDigits)++;
    }
    return true;
}

void visuTab(bool *tab){
    int i = 0;
    for(i=1; i<10; i++){
        printf("%d => ", (i));
        if(tab[i]){
            printf("true\n");
        }
        else{
            printf("false\n");
        }
    }
}

bool becomePandigital(int nbre){
    int n=nbre, nbreDigits = 0;
    bool tabB[10] = {false};
    while(true){
        if(!remplissageTab(tabB, n, &nbreDigits)){
            return false;
        }
        if(nbreDigits==9){
            return true;
        }
        n+=nbre;
    }
}

