#include <stdio.h>
#include <stdlib.h>
#include "../shared/sum.h"

#define LIMITE 999
#define NBRE_1 3
#define NBRE_2 5

int main(){
    const unsigned long enDouble = NBRE_1 * NBRE_2;

    printf("%d => %ld\n", NBRE_1, NBRE_1*sum1ToN(LIMITE/NBRE_1));
    printf("%d => %ld\n", NBRE_2, NBRE_2*sum1ToN(LIMITE/NBRE_2));
    printf("%ld => %ld\n", enDouble, enDouble*sum1ToN(LIMITE/enDouble));
    printf("%ld\n", (NBRE_1*sum1ToN(LIMITE/NBRE_1) + NBRE_2*sum1ToN(LIMITE/NBRE_2) - enDouble*sum1ToN(LIMITE/(enDouble))));

    return 0;
}
