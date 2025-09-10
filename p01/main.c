#include <stdio.h>
#include "../shared/sum.h"

#define LIMITE 999
#define NBRE_1 3
#define NBRE_2 5

int main()
{
    const unsigned int enDouble = NBRE_1 * NBRE_2;
    int sol;

    sol = (NBRE_1*sum1ToN(LIMITE/NBRE_1) + NBRE_2*sum1ToN(LIMITE/NBRE_2) -
           enDouble*sum1ToN(LIMITE/(enDouble)));

    printf("%d\n", sol);

    return 0;
}
