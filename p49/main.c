#include "liste.h"
#include "nbre.h"
#include "math.h"
#include "tabhach.h"
#include "../shared/nbre.h"

void visuTab(char *tab){
    unsigned char i = 0;
    for(i=0; i<10; i++){
	printf("tab[%d] : %d, ", i, tab[i]);
    }
    printf("\n");
}

void visuSol(l_tabhach *tabHach){
    printf("solutions : ");
    int i = 0;
    int tab[3] = {0};
    for(i=0; i<LIMITE_TAB; i++){
	l_tabhach p = tabHach[i];
	while(p!=NULL){
	    if((p->nbre_perm) >= 3){
		if(isSol(p->perm, tab)){
		    printf("%d%d%d, ", tab[2], tab[1], tab[0]);
		}
	    }
	    p = p->suiv;
	}
    }
    printf("\b\b \n");
}

int main(){
    int i = 0;
    short sum = 0;
    l_tabhach tabHach[LIMITE_TAB];

    initTabHach(tabHach);

    for(i=FIRST_NBRE; i<=LAST_NBRE; i+=2){
	if(isPrime(i)){
	    char *tab = (char *)digitsOfNbre(i);
	    sum = sumDigits(tab);
	    if(sum > LIMITE_TAB){
		printf("sum > LIMITE_TAB\n");
		exit(0);
	    }
	    else{
		ajoutElemTabHach(&tabHach[sum], i, tab);
	    }
	}
    }

    visuSol(tabHach);

    return 0;
} 
