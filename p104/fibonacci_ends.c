#include "fibonacci_ends.h"

bool pandigitalFibonacciEnds(mpz_t *n){
    return pandigitalFibonacciFirst(n) && pandigitalFibonacciLast(n);
}

bool pandigitalFibonacciFirst(mpz_t *n){
    static unsigned int previousDigit = 0;
    unsigned int nbreDigit = comptDigits(n);
    if(nbreDigit<9){
        return false;
    }
    static mpz_t n3;
    mpz_t n2;
    mpz_init_set(n2, *n);
    if(previousDigit != nbreDigit){
        if(previousDigit == 0){
            mpz_init_set_ui(n3, 10);
            mpz_pow_ui(n3, n3, nbreDigit-9);
        }
        else{
            mpz_mul_ui(n3, n3, 10);
        }
    }
    mpz_div(n2, *n, n3);
    //gmp_printf("n : %Zd, n2 : %Zd\n", *n, n2);
    return pandigitalFibonacciLast(&n2);
}

bool pandigitalFibonacciLast(mpz_t *n){
    mpz_t n2, n3, n4;
    mpz_init_set(n2, *n);
    mpz_init_set(n4, *n);
    mpz_init(n3);
    //pas de 0
    bool tab[10] = {true};
    unsigned int compt = 0;
    unsigned long ind;

    while((compt < 9) && (mpz_cmp_ui(n2, 1) >= 0)){
        mpz_div_ui(n2, n2, 10);
        mpz_mul_ui(n3, n2, 10);
        mpz_sub(n3, n4, n3);
        ind = mpz_get_ui(n3);
        if(tab[ind]){
            return false;
        }
        tab[ind] = true;
        mpz_div_ui(n4, n4, 10);
        compt++;
    }
    return (compt == 9);
}

unsigned int comptDigits(mpz_t *n){
    static unsigned int compt = 0;
    static mpz_t compar;
    if(compt == 0){
        mpz_init_set_ui(compar, 1);
    }

    while(mpz_cmp(*n, compar) > 0){
        compt++;
        mpz_mul_ui(compar, compar, 10);
    }
    return compt;
}

