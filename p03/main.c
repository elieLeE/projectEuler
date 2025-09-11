#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "../libC/src/math/prime.h"

#define NBRE 600851475143

bool prime_div(unsigned long div)
{
    return ((NBRE % div == 0) && (is_prime(NBRE / div)));
}

int main()
{
    unsigned long div = 3, max_div = 0, other_div;
    unsigned long rac = (unsigned long)sqrt(NBRE);

    while(div <= rac) {
        if(NBRE % div==0) {
            if((max_div < div) && is_prime(div)) {
                max_div = div;
            } else {
                other_div = NBRE / div;

                if((max_div < other_div) && is_prime(other_div)) {
                    max_div = other_div;
                }
            }
        }
        div = div + 2;
    }

    printf("%ld\n", max_div);

    return 0;
}

