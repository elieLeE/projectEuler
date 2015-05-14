#include "nbre.h"

char* digitsOfNbre(long n){
    long n2 = n, n3 = n;
    char *tab = (char *)calloc(10, sizeof(char));

    while(n2>1){
	n2 = n2/10;
	tab[(n3-n2*10)]++;
	n3 = n3/10;
    }
    return tab;
}

short sumDigits(char *tab){
    char i = 0;
    short sum = 0;
    for(i=0; i<LIMITE_TAB; i++){
	sum += tab[i];
    }
    return sum;
}
