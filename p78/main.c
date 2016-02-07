#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

void initTab(mpz_t* tab, int taille, mpz_t* mod){
    int i;
    mpz_init(*mod);
    for(i=0; i<taille; i++){
	mpz_init(tab[i]);
    }
    mpz_set_ui(tab[0], 1);
}

long nbreSum(int n){
    int i, j;
    long div = 1000000;
    mpz_t* tab = malloc((n+1)*sizeof(mpz_t));
    mpz_t mod;
    initTab(tab, n+1, &mod);

    for(i=1; i<=n-1; i++){
	for(j=i; j<=n; j++){
	    mpz_add(tab[j], tab[j], tab[j-i]);
	}
	mpz_mod_ui(mod, tab[i], div);
	if(mpz_cmp_ui(mod, 0) == 0){
	    return i;
	}
    }
    return 0;
}

int main(){
    int max = 100000;
    printf("%ld\n", (nbreSum(max)));

    return 0;
}
