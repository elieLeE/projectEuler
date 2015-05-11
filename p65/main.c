#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

int sum_digits(long double nbre){
    char chaine[70];
    int sum = 0, i = 0;
    sprintf(chaine, "%Lf", nbre);
    while(chaine[i] != 46){
	sum = sum + (chaine[i] -48);
	i++;
    }
    return sum;
}

int main(){
    int n = 33;
    mpz_t x, y, x2, y2, tmp, tmp2;
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

    gmp_printf("%Zd\n", x);

    return 0;
}

