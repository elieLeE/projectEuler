#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "triangle.h"

#define LIMITE 1001

bool coPrime(int a, int b){
    int r = a-(a/b)*b;
    while(r!=0){
	a = b;
	b = r;
	r = a-(a/b)*b;
	//printf("a : %d, b : %d, r : %d\n", a, b, r);
    }
    return b==1;
}

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
    int compt = 0, compt2=0;

    /*affOneRect(12);
    affOneRect(24);
    affOneRect(30);
    affOneRect(36);
    affOneRect(40);
    affOneRect(48);
    affOneRect(120);*/

    /*if(coPrime(4, 3)){
	printf("(3, 4) co-prime\n");
    }
    else{
	printf("(3, 4) pas co-prime\n");
    }*/


    //affOneRect(1223548);
    
    int tabPer[LIMITE];
    int i, j, k, n2, m2;
    int a, b, c, p;
    int x;

    /*for(i=0; i<limite; i++){
	printf("tab[i] : %d\n", tabPer[i]);
    }*/

    for(i=1; i<LIMITE; i++){
	for(j=1; j<LIMITE; j++){
	    if(((i-j)%2==0) && coPrime(i, j)){
		//printf("(%d, %d)\n", i, j);
		m2 = i*i;
		n2 = j*j;
		a = m2-n2;
		b = 2*i*j;
		c = m2+n2;
		p = a+b+c;
		for(k=p, x=1; k<LIMITE; k+=p, x++){
		    if(k==840){
			printf("(%d, %d, %d), k : %d => (%d, %d, %d)\n", a, b, c, x, x*a, x*b, x*c);
		    }
		    tabPer[k]++;
		}
	    }
	}
    }
    /*for(i=0; i<limite; i++){
	printf("tab[i] : %d\n", tabPer[i]);
    }*/

    int max = 0, indMax=0;

    for(i=0; i<LIMITE; i++){
	if(max<tabPer[i]){
	    max = tabPer[i];
	    indMax = i;
	}
    }
    printf("indMax : %d, nbre de sol : %d\n", indMax, max);




    

    return 0;
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
