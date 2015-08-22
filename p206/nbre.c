#include "nbre.h"

void visualiserTab(char *tab);

void digitsOfNbre(long n, char* tab){
    long n2 = n, n3 = n;
    int i = NBRE_DIGITS-1;
    while(n2>=1){
	n2 = n2/10;
	tab[i] = n3-n2*10;
	i--;
	n3 = n3/10;
    }
    //printf("%lld => \n", n);
    //visualiserTab(tab);
}

void visualiserTab(char *tab){
    int i = 0;
    for(i=0; i<NBRE_DIGITS; i++){
	printf("%d", tab[i]);
    }
    printf("\n");
}

bool nbreOK(long n){
    //printf("dans nbreOK\n");
    char tab[NBRE_DIGITS] = {0};
    digitsOfNbre(n, tab);

    int i = 0;
    for(i=0; i<9; i++){
	if(tab[2*i] != (i+1)){
	    //printf("tab[%d] : %d, (i+1) : %d => faux\n", 2*i, i, (i+1));
	    return false;
	}
    }
    //printf("apres for\n");
    //printf("tab[NBRE_DIGITS-1] : %d\n", tab[NBRE_DIGITS-1]);
    if(tab[NBRE_DIGITS-1] == 0){
	return true;    
    }
    return false;
}



