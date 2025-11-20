#include <stdio.h>
#include <stdlib.h>
#include "nbre.h"
#include "../shared/alloc.h"

int main(){
    unsigned int i;
    unsigned int compt = 0;

    for(i=4; i<=LIMITE; i++){
	compt = compt + nbreFracIrr(i);
    }

    printf("%d\n", compt);

    return 0;
}
