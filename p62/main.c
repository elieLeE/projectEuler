#include "liste.h"
#include "nbre.h"
#include "math.h"

int main(){
    char i = 0;
    long nbre = 0;
    short sum = 0;

    l_tabhach tabHach[LIMITE_TAB];
    initTabHach(tabHach);

    l_perm l = creerListe();
    for(i=0; i<=100; i++){
	printf("%ld\n", (long)pow(i, 3));
	ajoutElem(&l, (long)pow(i, 3));
    }

    visuListePerm(l);
    printf("\n");

    for(i=0; i<=100; i++){
	printf("debut for %d\n", i);
	nbre = (long)pow(i, 3);
	printf("%ld\n", nbre);
	char *tab = (char *)digitsOfNbre(nbre);
	sum = sumDigits(tab);
	if(sum > LIMITE_TAB){
	    printf("sum > LIMITE_TAB\n");
	    exit(0);
	}
	else{
	    printf("dans le else\n");
	    ajoutElemTabHach(tabHach[sum], nbre, tab);
	}
	printf("fin for\n");
    }
    return 0;
}
