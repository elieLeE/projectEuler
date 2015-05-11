#include "nbre.h"

int sum_diviseurs(int nbre){
    int i = 1, sum = 1;
    if(nbre%2 == 0){
	sum += 2 + nbre/2;
    }
    for(i=3; i*i<=nbre; i++){
	if(nbre%i == 0){
	    //printf("%d\n", i);
	    sum += i + nbre/i; 
	}
    }
    return sum;
}

