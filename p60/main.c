#include "nbre.h"

int main(){
    int nbreActuel = 1;
    int i = 0;

    for(i=0; i<10; i++){
	nbreActuel = nextNbrePrime(nbreActuel);
	printf("%d\n", nbreActuel);
    }

    return 0;
}

