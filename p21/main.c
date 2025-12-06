#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/prime.h"

#define LIMIT 10000

int main()
{
    unsigned long amicable_numbers_sum = 0;
    gv_t(uint64) primes;

    gv_init(&primes);

    get_all_primes_below_n(LIMIT, &primes);

    for (unsigned long i = 2; i < LIMIT; i++) {
        unsigned long divisors_sum1, divisors_sum2;

        divisors_sum1 = get_proper_divisors_sum_of_n(i, &primes);

        if (divisors_sum1 <= i || divisors_sum1 > LIMIT) {
            continue;
        }

        divisors_sum2 = get_proper_divisors_sum_of_n(divisors_sum1, &primes);
        if (divisors_sum2 == i) {
            amicable_numbers_sum += i + divisors_sum1;
        }
    }

    gv_wipe(&primes, NULL);

    printf("%ld\n", amicable_numbers_sum);

    return 0;
}
