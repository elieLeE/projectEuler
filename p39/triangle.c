#include "triangle.h"

bool isTriRectangle(int a, int b, int c){
    return (a*a + b*b == c*c);
}

int nbreTriangleRect(int p){
    int i, j, k, compt = 0;
    for(i=1; i<p/2; i++){
	for(j=i+1; j<p/2; j++){
	    k = p-i-j;
	    if(i+j>k){
		if(isTriRectangle(i, j, k)){
		    if(p==840){
			printf("(%d, %d, %d)\n", i, j, k);
		    }
		    compt++;
		}
	    }
	}
    }
    return compt;
}

