#include <math.h>
#include "structure.h"

int main(){
    alpha a;

    a.a = 39;
    a.b = 5;
    a.n = 61;

    printf("norme de %s : %ld\n", visuAlpha(a), normeAlpha(a));
    printf("%s² = %s\n", visuAlpha(a), visuAlpha(alphaCarreSur2(a)));
    printf("%s^3 = %s\n", visuAlpha(a), visuAlpha(alphaCubeSur8(a)));
    printf("norme(%s^3) = %lf\n", visuAlpha(a), fabs(normeAlpha(alphaCubeSur8(a))));

    short n = 4, ajoutN = 5;
    short i;
    for(i=2; i<=1000; i++){
	if(i!=n){
	    printf("i : %d\n", i);
	}
	else{
	    n = n+ajoutN;
	    ajoutN += 2;
	}
    }

    return 0;
}
