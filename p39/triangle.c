#include "triangle.h"

bool isTriRectangle(int a, int b, int c){
    return (a*a + b*b == c*c);
}

int nbreTriangleRect(int p){
    int i, j, k, compt = 0;
    for(i=1; i<p/2; i++){
	for(j=1; j<p/2; j++){
	    k = p-i-j;
	    if(isTriRectangle(i, j, k)){
		compt++;
	    }
	}
    }
    return compt;
}

