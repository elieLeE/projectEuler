/*
 * probleme 92 => 534 ms
 */

#include "nbre.h"
#include "tab.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_TAB 568	//=> maximun = 7*(9²) => sommes des carres des digits pour 9 999 999 => 567 cases necessaires. pas envie de faire i-1 => 568 cases.
#define NBRE_DE_NBRE_A_EVALUER 10000000

int main(){
    int compt = 0;
    int i =1;
    int sum = 0;
    bool tab[TAILLE_TAB] = {false};
    char carre[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    char tab_nbre[7] = {1, 0, 0, 0, 0, 0, 0};
   
    for(i=1; i<TAILLE_TAB; i++){
	sum = carre_digits(i);
	while(sum != 1 & sum !=89){
	    sum = carre_digits(sum);
	}
	if(sum == 89){
	    tab[i] = true;
	}
    }

    while(next_nbre(tab_nbre)){
	if(tab[sum_carre_digits(carre, tab_nbre)]){
	    compt++;
	}
    }
    printf("%d\n", compt);

    return 0;
}

