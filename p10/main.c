#include "stdio.h"
#include "math.h"

#include "../libC/src/math/prime.h"
#include "../libC/src/mem/mem.h"

#define LIMIT 2000000

int main(void)
{
    unsigned long *primes;
    unsigned int primes_count;
    unsigned long sum = 0;
    unsigned int size_tab;

    /* it appears that there is approximately N / log(N) primes number below N.
     * So, we do not need to allocate a tab with the size of N, but just
     * N / log(N). Multiply anyway by 2 in order to have a margin. */
    size_tab = (LIMIT / ((unsigned int)log(LIMIT))) * 2;
    primes = p_calloc(sizeof(long) * size_tab);

    primes_count = get_all_primes_below_n(LIMIT, size_tab, primes);

    for (unsigned int i = 0; i <= primes_count; i++) {
        sum += primes[i];
    }

    printf("%ld\n", sum);

    return 0;
}
