#include "nbre.h"

int carre_digits(int nbre){
    int div = 10, sum = 0;
    int nbre2, digit;
    while(nbre > 9){
	nbre2 = nbre;
	nbre = nbre/10;
	digit = nbre2 - nbre*10;
	sum = sum + digit*digit;
    }
    sum = sum + nbre*nbre;
    return sum;
}

int sum_carre_digits(char tab_carre[], char tab_nbre[]){
    int sum = 0, i = 0;
    for(i=0; i<7; i++){
	sum += tab_carre[tab_nbre[i]];
    }
    return sum;
}

