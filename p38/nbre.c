#include "nbre.h"

long nbreToPandigital(int n){
    int nbreDigits = 0, nbreDigits2;
    long nbre = n, mul = 1, n2=n;
    while(true){
	n2+=n;
	nbreDigits2 = nbreDigit(n2);
	nbreDigits+=nbreDigits2;
	if(nbreDigits>=9){
	    return nbre;
	}
	mul = pow(10, nbreDigits2);
	nbre*=mul;
	nbre += n2;
    }
    return nbre;
}

int nbreDigit(int n){
    int n2 = n, nbreDigits = 0;
    while(n>0){
	n2 = n/10;
	n=n-n2*10;
	n = n2;
	nbreDigits++;
    }
    return nbreDigits;
}

