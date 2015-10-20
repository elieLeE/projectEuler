#include "nbre.h"

int sumFactDigits(int n){
    static int tabFact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int sum = 0;
    int n2 = n, d;
    while(n>=1){
	n2 = n/10;
	d = n-n2*10;
	sum += tabFact[d];
	n = n2;
	//printf("n : %d, d : %d\n", n, d);
    }
    return sum;
}

