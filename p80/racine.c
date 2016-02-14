#include "racine.h"

unsigned int sum100DecimalDigits(int n){
    unsigned int sum = 0, d;
    unsigned int i = 0;
    int debCompt = nbreDigits(n);
    int deb = 1, res;

    while(i<NBRE_DIGITS){
	d = nbreSoustraction(n, &deb, &res);
	deb = nextDeb(deb);
	n = nextN(res, d);
	if(debCompt > 0){
	    debCompt--;
	}
	else{
	    sum = sum + d;
	    i++;
	}
    }

    return sum;
}

int nbreSoustraction(int n, int *deb, int* res){
     int compt = 0;
     n = n - (*deb);
     while(n>=0){
	 printf("n => %d, deb => %d\n", n, *deb);
	 *deb = *deb + 2;
	 n = n - (*deb);
	 compt++;
     }
     *res = n + (*deb);
     *deb = *deb-2;
     printf("n => %d, deb => %d\n", n, *deb);
     return compt;
}

int nextDeb(int impair){
    return (impair+1)*10+1;
}

int nextN(int a, int b){
    return a*nbreDigits(b) + b;
}
