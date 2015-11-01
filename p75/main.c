#include <stdio.h>
#include <stdbool.h>
#include "triangle.h"

void affOneRect(long n){
    if(oneTriangleRect(n)){
	printf("%ld one\n", n);
    }
    else{
	printf("%ld not one\n", n);
    }
}

int main(void)
{
    int i = 1500000, compt = 0, compt2=0;

    affOneRect(12);
    affOneRect(24);
    affOneRect(30);
    affOneRect(36);
    affOneRect(40);
    affOneRect(48);
    affOneRect(120);

    //affOneRect(1223548);

    for(i=1; i<1500000; i++){
	if(compt2==10000){
	    printf("%d\n", i);
	    compt2=0;
	}
	compt2++;
	if(oneTriangleRect(i)){
	    compt++;
	}
    }

    printf("compt : %d\n", compt);

    return 0;
}
