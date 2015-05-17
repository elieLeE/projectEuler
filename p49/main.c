#include "liste.h"
#include "nbre.h"
#include "math.h"

void visuTab(char *tab){
    char i = 0;
    for(i=0; i<10; i++){
	printf("tab[%d] : %d, ", i, tab[i]);
    }
    printf("\n");
}

void visuSol(l_tabhach *tabHach){
    printf("solutions : \n");
    int i = 0, j = 0;
    char c;
    int tab[3] = {0};
    for(i=0; i<LIMITE_TAB; i++){
	l_tabhach p = tabHach[i];
	while(p!=NULL){
	    if((p->nbre_perm) >= 3){
		if(isSol(p->perm, tab)){
		    printf("\t%d%d%d\n", tab[2], tab[1], tab[0]);
		}
	    }
	    p = p->suiv;
	}
    }
}

int main(){
    int i = 0;
    long nbre = 0;
    short sum = 0;
    l_tabhach p = NULL;
    l_tabhach tabHach[LIMITE_TAB];

    initTabHach(tabHach);
    l_perm l = creerListe();

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
