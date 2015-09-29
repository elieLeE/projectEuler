#include <math.h>
#include "structure.h"
#include <limits.h>

#define MAX 1000
int main(){
    //printf("norme de %s : %lld\n", visuAlpha(a), normeAlpha(a));
    //printf("%s² = %s\n", visuAlpha(a), visuAlpha(alphaCarreSur2(a)));
    //printf("%s^3 = %s\n", visuAlpha(a), visuAlpha(alphaCubeSur8(a)));
    //printf("norme(%s^3) = %lld\n", visuAlpha(a), fabs(normeAlpha(alphaCubeSur8(a))));

    /*short n = 4, ajoutN = 5;
    short i, d = 0;
    alpha res;
    long long max = 0;
    for(i=2; i<=MAX; i++){
	if(i!=n){
	    res = searchSol(i);
	    if(res.a < 0){
		printf("i : %d => ressultat NULL\n", i);
	    }
	    else{
		if(res.a > max){
		    max = res.a;
		    d = i;
		}
		//printf("i : %d, => res : %s, norme(res) : %lld\n", i, visuAlpha(res), normeAlpha(res));
	    }
	}
	else{
	    n = n+ajoutN;
	    ajoutN += 2;
	}
    }

    printf("max : %lld, d : %d\n", max, d);*/

    printf("LL_max : %lld\n", LLONG_MAX);

    printf("ici\n");
    mpz_t *f = calloc(1, sizeof(mpz_t));
    mpz_init(*f);
    printf("ici2\n");

    mpz_t m;
    mpz_init(m);
    mpz_set_ui(m, 10);
    gmp_printf("m : %Zd\n", m);

    alpha a;
    /*a.a = 39;
    a.b = 5;
    a.n = 61;*/
    /*alphaCarreSur2(&a);
    printf("a²/2 : %s\n", visuAlpha(a));*/
    //alphaCubeSur8(&a);
    /*alphaSixSur64(&a);
    printf("a^6/64 : %s\n", visuAlpha(a));*/

    printf("main 1\n");
    //printf("searchSol(61) : %s\n", visuAlpha(searchSol(61)));
    visuAlpha(searchSol(61));
    printf("main 2\n");
    /*printf("norme(searchSol(61)) : %lld\n", normeAlpha(searchSol(61)));*/
    /*printf("searchSol(103) : %s\n", visuAlpha(searchSol(103).alp));
    printf("searchSol(58) : %s\n", visuAlpha(searchSol(58).alp));*/
    //printf("searchSol(13) : %lld\n", searchSol(13));
    //printf("searchSol(888) : %s, norme : %lld\n", visuAlpha(searchSol(889)), normeAlpha(searchSol(889)));

    printf("%ld\n", sizeof(long long));

    return 0;
}
