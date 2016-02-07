#include <math.h>
#include "structure.h"
#include <limits.h>

#define MAX 1000
int main(){
    short n = 4, ajoutN = 5;
    short i, d = 0;
    alpha res;
    mpz_t max;
    mpz_init(max);

    for(i=2; i<=MAX; i++){
	if(i!=n){
	    res = searchSol(i);
	    if(mpz_cmp_ui(res.a, 0)==0){
		printf("i : %d => resultat NULL\n", i);
	    }
	    else{
		if(mpz_cmp(res.a, max)>0){
		    mpz_set(max, res.a);
		    d = i;
		}
	    }
	}
	else{
	    n = n+ajoutN;
	    ajoutN += 2;
	}
    }

    gmp_printf("max : %Zd, d : %d\n", max, d);

    return 0;
}
