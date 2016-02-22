#include <stdio.h>
#include <stdlib.h>
#include "nbre.h"

int main(){
    unsigned int tabPrime[TAILLE_TAB_PRIME] = {0};

    remplissageTabPrime(tabPrime);
    //visuTab(tabPrime, TAILLE_TAB_PRIME, (void(*)(void *))visuElem, "\b\b \n");

    unsigned int i = 1;
    while(nbreAdd(i, 0, tabPrime) < LIMITE){
	i++;
    }
    printf("%d\n", i);
    //visuTab(tabPrime);

    /*unsigned int n = 10;
    printf("%d => %d\n", n, nbreAdd(n, 0, tabPrime));*/

    return 0;
}
