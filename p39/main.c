#include <stdio.h>
#include <stdbool.h>
#include "triangle.h"

int main(void)
{
    int i, max = 0, indMax, n;

    for(i=1; i<=1000; i++){
	n = nbreTriangleRect(i);
	if(n>max){
	    max = n;
	    indMax=i;
	}
    }

    printf("p : %d, => %d\n", indMax, max);

    return 0;
}
