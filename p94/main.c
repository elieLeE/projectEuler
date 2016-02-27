#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ALGO 1

#if ALGO
#define LIMITE 1000000000
#else
#define LIMITE 100000
#endif

bool almostEquilateral(unsigned long *c, unsigned long *add, unsigned long n){
    while(*c>n){
	*add = *add -2;
	*c = *c - *add;
    }
    while(*c<n){
	*c = *c + *add;
	*add = *add + 2;
    }
    return (*c == n);
}

int main(){
    unsigned long a;
    unsigned long s1, s2;
    unsigned long carre;
    unsigned long addCarre;
    unsigned long sum = 0;

    carre = 16;
    addCarre = 9;
    s1 = 0;
    
    for(a=3; 3*a-1<=LIMITE; a=a+2){
	s1 = s1+12*(a-2)+8;
	if(almostEquilateral(&carre, &addCarre, s1)){
	    sum = sum + (3*a-1);
	}
	s2 = s1 + 4*a;
	if(almostEquilateral(&carre, &addCarre, s2)){
	    sum = sum + (3*a+1);
	}
    }

    printf("%ld\n", sum);
    return 0;
}
