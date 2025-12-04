#include <stdio.h>

#include "../libC/src/math/sum.h"

#define LIMITE 999
#define NBRE_1 3
#define NBRE_2 5

int main()
{
    const unsigned int en_double = NBRE_1 * NBRE_2;
    int sol;

    sol = (NBRE_1 * sum_1_to_n(LIMITE / NBRE_1) +
           NBRE_2 * sum_1_to_n(LIMITE / NBRE_2) -
           en_double * sum_1_to_n(LIMITE / (en_double)));

    printf("%d\n", sol);

    return 0;
}
