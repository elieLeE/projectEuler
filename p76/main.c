#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 0

long nbreSum(int n, int min, int dec){
    int i=0, compt = 1;
#if DEBUG
    for(i=0; i<dec; i++){
	printf("\t");
    }
    printf("(%d, %d) => ", n, min);
#endif
    if(n==1){
#if DEBUG
	printf("1\n");
#endif
	return 1;
    }
    for(i=1; i<=floor(n/2); i++){
	if(i>=min){
#if DEBUG
	    printf("\n");
#endif
	    compt += nbreSum(n-i, i, dec+1);
	}
    }
#if DEBUG
    for(i=0; i<dec; i++){
	printf("\t");
    }
    printf("%d\n", compt);
#endif
    return compt;
}

void affTab(int *tab, int taille){
    int i;
    for(i=0; i<taille; i++){
	printf("%d, ", tab[i]);
    }
    printf("\n");
}

long nbreSum2(int n){
    int i, j;
    int* tab = malloc((n+1)*sizeof(int));
    tab[0] = 1;

    for(i=1; i<=n-1; i++){
	for(j=i; j<=n; j++){
	    tab[j] += tab[j-i];
	}
    }
    return tab[n];
}

int main(){
    //printf("%ld\n", (nbreSum(100, 1, 0)-1));
    printf("%ld\n", (nbreSum2(100)));

    return 0;
}
