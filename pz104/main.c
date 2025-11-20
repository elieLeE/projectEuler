#include <stdio.h>
#include <stdlib.h>
#include "fibonacci_ends.h"

int main(){
    mpz_t f1, f2, f3;

    mpz_init_set_ui(f1, 2);
    mpz_init_set_ui(f2, 1);
    mpz_init_set_ui(f3, 1);

    unsigned int compt = 3;

    while(!pandigitalFibonacciEnds(&f1)){
        compt++;
        mpz_set(f3, f2);
        mpz_set(f2, f1);
        mpz_add(f1, f2, f3);
    }

    gmp_printf("%d\n", compt);
    return 0;
}
