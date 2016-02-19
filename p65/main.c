#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>
#include "../shared/alloc.h"

mpz_t* sum_digits(mpz_t *nbre){
    mpz_t *sum, n1, n2, d;
    sum = my_calloc(1*sizeof(mpz_t));
    mpz_init(n1);
    mpz_init(n2);
    mpz_init(d);
    mpz_init(*sum);
    mpz_set(n2, *nbre);
    mpz_set_ui(*sum, 0);
    while(mpz_cmp_ui(*nbre, 0)>0){
	mpz_div_ui(*nbre, *nbre, 10);
	mpz_mul_ui(n1, *nbre, 10);
	mpz_sub(d, n2, n1);
	mpz_set(n2, *nbre);
	mpz_add(*sum, *sum, d);
    }
    return sum;
}

int main(){
    int n = 33;
    mpz_t x, y, x2, y2, tmp, tmp2;
    mpz_t *result;
    mpz_init(x);
    mpz_init(y);
    mpz_init(x2);
    mpz_init(y2);
    mpz_init(tmp);
    mpz_init(tmp2);
    mpz_add_ui(x, x, (2*n+1));
    mpz_add_ui(y, y, (2*n+2));

    while(n >1){
	n--;
	mpz_mul_ui(tmp, y, (2*n+1));
	mpz_mul_ui(tmp2, x, (2*n));
	mpz_add(x2, tmp, tmp2);

	mpz_mul_ui(tmp, y, (2*n+2));
	mpz_mul_ui(tmp2, x, (2*n+1));
	mpz_add(y2, tmp, tmp2);

	mpz_add_ui(x, x2, 0);
	mpz_add_ui(y, y2, 0);
    }
    mpz_mul_ui(tmp, y, 2);
    mpz_add(tmp2, x, tmp);
    mpz_add_ui(x, tmp2, 0);

    result = sum_digits(&x);
    gmp_printf("%Zd\n", *result);
    free(result);

    return 0;
}

