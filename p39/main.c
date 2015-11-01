#include <stdio.h>
#include <stdbool.h>
#include "triangle.h"

int main(void)
{
    int i = 10000, max = 0, indMax, n;

    for(i=1; i<1000; i++){
	n = nbreTriangleRect(i);
	if(n>max){
	    max = n;
	    indMax=i;
	}
    }

    printf("p : %d\n", indMax);

    return 0;
}
