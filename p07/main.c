#include <stdio.h>

#include "../libC/src/math/prime.h"

#define LIMIT 10001

int main(void)
{
    gv_t(uint64) primes;

    gv_init_size(&primes, LIMIT);

    get_all_n_first_primes(LIMIT, &primes);

    printf("%ld\n", primes.tab[LIMIT - 1]);

    gv_wipe(&primes, NULL);

    return 0;
}
