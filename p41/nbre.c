#include "nbre.h"

bool isPandigital(long n){
    long n2 = n, n3 = n;
    char tab[10] = {false};
    char digit = 0;
    char nbre_digit = 0, i;
    while(n2>=1){
	nbre_digit++;
	n2 = n2/10;
	digit = (char)(n3-n2*10);
	if(tab[digit]){
	    return false;
	}
	else{
	    if(digit == 0){
		return false;
	    }
	    tab[digit] = true;
	}
	n3 = n3/10;
    }
    for(i=9; i>nbre_digit; i--){
	if(tab[i]){
	    return false;
	}
    }
    return true;
}

bool isPrime(long n){
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
