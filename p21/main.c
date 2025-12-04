#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/prime.h"

#define LIMIT 10000

/* The fact of allocating and deallocation the vector decreases a little the
 * performance of this code but it is still very fast, so anyway */
unsigned long
get_divisors_sum_of_n(unsigned long n, const gv_t(uint64) *primes)
{
    unsigned sum;
    gv_t(primes_factors) primes_factors;
    gv_t(uint64) divisors;

    gv_init(&primes_factors);
    gv_init(&divisors);

    get_all_primes_factors_of_n(n, primes, &primes_factors);
    get_all_divisors_of_n_from_prime_factors(&primes_factors, &divisors);
    sum = get_all_proper_divisors_sum_from_all_divisors(n, &divisors);

    gv_wipe(&divisors, NULL);
    gv_wipe(&primes_factors, NULL);

    return sum;
}

int main()
{
    unsigned long amicable_numbers_sum = 0;
    gv_t(uint64) primes;

    gv_init(&primes);

    get_all_primes_below_n(LIMIT, &primes);

    for (unsigned long i = 2; i < LIMIT; i++) {
        unsigned long divisors_sum1, divisors_sum2;

        divisors_sum1 = get_divisors_sum_of_n(i, &primes);

        if (divisors_sum1 <= i) {
            continue;
        }

        divisors_sum2 = get_divisors_sum_of_n(divisors_sum1, &primes);
        if (divisors_sum2 == i) {
            amicable_numbers_sum += i + divisors_sum1;
        }
    }

    gv_wipe(&primes, NULL);

    printf("%ld\n", amicable_numbers_sum);

    return 0;
}
