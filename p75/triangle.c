#include "triangle.h"

bool isTriRectangle(long a, long b, long c){
    long a2 = a*a, b2 = b*b, c2 =c*c;
    //printf("a2 : %ld, b2 : %ld, c2 : %ld\n", a2, b2, c2);
    return (a*a + b*b == c*c);
}

bool oneTriangleRect(int p){
    long i, j, k;
    bool b = false;
    for(i=1; i<p/2; i++){
	for(j=i; j<p/2; j++){
	    k = p-i-j;
	    if(isTriRectangle(i, j, k)){
		//printf("(%ld, %ld, %ld) rectangle\n", i, j, k);
		if(b){
		    return false;
		}
		b = true;
	    }
	}
    }
    return true;
}

