#include "stdio.h"
#include "math.h"

#include "../libC/src/math/prime.h"
#include "../libC/src/mem/mem.h"

#define LIMIT 2000000

int main(void)
{
    gv_t(uint64) primes;
    unsigned long sum = 0;
    int size_vector;

    /* it appears that there is approximately N / log(N) primes number below N.
     * So, we do not need to allocate a tab with the size of N, but just
     * N / log(N). Multiply anyway by 2 in order to have a margin. */
    size_vector = (LIMIT / ((unsigned int)log(LIMIT))) * 2;

    gv_init_size(&primes, size_vector);

    get_all_primes_below_n(LIMIT, &primes);

    gv_for_each_pos(pos, &primes) {
        sum += primes.tab[pos];
    }

    printf("%ld\n", sum);

    p_free((void **)&primes);

    return 0;
}
