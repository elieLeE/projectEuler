#include "liste.h"
#include "nbre.h"
#include "math.h"
#include "tabhach.h"

void visuTab(char *tab){
    unsigned char i = 0;
    for(i=0; i<10; i++){
	printf("tab[%d] : %d, ", i, tab[i]);
    }
    printf("\n");
}

int main(){
    unsigned int i = 0;
    long nbre = 0;
    short sum = 0;
    l_tabhach p = NULL;
    l_tabhach tabHach[LIMITE_TAB];

    initTabHach(tabHach);

    for(i=1; i<=LIMITE_SEARCH; i++){
	nbre = (long)pow(i, 3);
	char *tab = (char *)digitsOfNbre(nbre);
	sum = sumDigits(tab);
	if(sum > LIMITE_TAB){
	    printf("sum > LIMITE_TAB\n");
	    exit(0);
	}
	else{
	    p = (l_tabhach)ajoutElemTabHach(&tabHach[sum], nbre, tab);
	    if(p != NULL && (p->nbre_perm) == NBRE_PERM){
		break;
	    }
	}
    }

    if(p!= NULL){
	if((p->nbre_perm) == NBRE_PERM){
	    visuListePerm(p->perm);
	    printf("\nmin : %ld\n", searchMin(p->perm));
	}
	else{
	    printf("solution non trouvée\n");
	}
    }

    return 0;
} 
