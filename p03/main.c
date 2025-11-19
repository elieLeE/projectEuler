#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "../libC/src/math/prime.h"

#define N 600851475143

int main()
{
    unsigned long div = 3, max_div = 0;
    unsigned long other_div;

    while (div * div <= N) {
        if (N % div == 0) {
            if ((max_div < div) && is_prime(div)) {
                max_div = div;
            } else {
                other_div = N / div;

                if ((max_div < other_div) && is_prime(other_div)) {
                    max_div = other_div;
                }
            }
        }
        div = div + 2;
    }

    printf("%ld\n", max_div);

    return 0;
}

