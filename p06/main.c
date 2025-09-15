#include <stdio.h>
#include <math.h>

#include "../libC/src/math/sum.h"

#define LIMITE 100

int main(void)
{
    unsigned long n;

    n = pow(sum_1_to_n(LIMITE), 2) - sum_carre_1_to_n(LIMITE);

    printf("%ld\n", n);
    return 0;
}


