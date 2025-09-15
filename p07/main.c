#include <stdio.h>

#include "../libC/src/math/prime.h"

#define LIMIT 10001

int main(void)
{
    unsigned long primes[LIMIT] = {0};

    get_all_n_first_primes(LIMIT, LIMIT, primes);

    printf("%ld\n", primes[LIMIT - 1]);

    return 0;
}
