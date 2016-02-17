#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../shared/nbre.h"

unsigned int nbreToTab(char *tab, unsigned int n){
    unsigned int n2, i = 0;
    char d;
    while(n>=1){
	n2 = n/10;
	d = n - n2*10;
	tab[i] = d;
	n = n2;
	i++;
    }
    return i;
}

bool isPalindrome(unsigned int n){
    static char tabDigit[6];
    unsigned int nbreDigits = nbreToTab(tabDigit, n);
    unsigned int i;

    for(i=0; i<nbreDigits/2; i++){
	if(tabDigit[i] != tabDigit[nbreDigits-i-1]){
	    return false;
	}
    }

    return true;
}

int main(){
    unsigned int n = 100, m = 101;
    unsigned int maxPalindrome = 0, x;

    while(n<1000){
	m = n+1;
	while(m<1000){
	    x = n*m;
	    if(isPalindrome(x)){
		if(x > maxPalindrome){
		    maxPalindrome = x;
		}
	    }
	    m++;
	}
	n++;
    }

    printf("%d\n", maxPalindrome);
    return 0;
}

