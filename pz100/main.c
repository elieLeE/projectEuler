#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <math.h>

#define NBRE_BIT_PRECISION 10000 

int main(){
    double b_n = 1, b_n_plus_1 = 0, t_n = 1, t_n_plus_1 = 0;

    while(t_n < 1000000000000.0){
	b_n_plus_1 = 3*b_n + 2*t_n -2;
	t_n_plus_1 = 4*b_n + 3*t_n -3;

	b_n = b_n_plus_1;
	t_n = t_n_plus_1;
    }

    printf("t_n : %lf, b_n : %lf\n", t_n, b_n);

    return 0;
}

