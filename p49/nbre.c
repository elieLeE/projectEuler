#include "nbre.h"

char* digitsOfNbre(int n){
    int n2 = n, n3 = n;
    char *tab = (char *)calloc(10, sizeof(char));

    while(n2>=1){
	n2 = n2/10;
	tab[(n3-n2*10)]++;
	n3 = n3/10;
    }
    return tab;
}

short sumDigits(char *tab){
    char i = 0;
    short sum = 0;
    for(i=0; i<10; i++){
	sum += (i*tab[i]);
    }
    return sum;
}

bool isPrime(int n){
    if(n%2 == 0){
	return false;
    }
    int i = 0;
    for(i=3; i*i<=n; i+=2){
	if(n%i == 0){
	    return false;
	}
    }
    return true;
}
