#include "racine.h"

unsigned int sum100DecimalDigits(int nbre){
    unsigned int sum = 0, d;
    unsigned int i = 0;
    mpz_t deb, res, n;
    mpz_init(deb);
    mpz_init(res);
    mpz_init(n);

    mpz_set_ui(deb, 1);
    mpz_set_ui(n, nbre);

    while(i<NBRE_DIGITS){
	d = nbreSoustraction(n, &deb, &res);
	nextDeb(&deb);
	nextN(&n, res);
	sum = sum + d;
	i++;
    }
    return sum;
}

int nbreSoustraction(mpz_t n, mpz_t *deb, mpz_t* res){
     int compt = 0;
     mpz_sub(n, n, *deb);
     while(mpz_cmp_ui(n, 0)>=0){
	 mpz_add_ui(*deb, *deb, 2);
	 mpz_sub(n, n, *deb);
	 compt++;
     }
     mpz_add(*res, n, *deb);
     mpz_sub_ui(*deb, *deb, 2);
     return compt;
}

void nextDeb(mpz_t* impair){
    mpz_add_ui(*impair, *impair, 1);
    mpz_mul_ui(*impair, *impair, 10);
    mpz_add_ui(*impair, *impair, 1);
}

void nextN(mpz_t* n, mpz_t res){
    mpz_mul_ui(*n, res, 100);
}
