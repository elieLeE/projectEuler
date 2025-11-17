#include <stdio.h>
#include <string.h>

#include "../libC/src/math/nber_helper.h"
#include "../libC/src/math/prime.h"

#define DIVISORS_NBER_LIMITE 500

/* It is possible to demonstrate that the number of N is equal to the
 * multiplication of all the power of primes factors N.
 * So, if N = p1^a1 * p2^a2 * p3^a3...,
 * then N will have (a1 + 1) * (a2 + 1) * (a3 + 1)... divisors
 * (cf here: https://mathschallenge.net/index.php?section=faq&ref=number/number_of_divisors)
 */
int main(void)
{
    unsigned long n = 1;
    gv_t(uint64) primes;
    gv_t(primes_factors) primes_factors;

    gv_init(&primes);
    gv_init(&primes_factors);

    get_all_n_first_primes(DIVISORS_NBER_LIMITE, &primes);

    for (unsigned long idx = 2;; idx++) {
        n = get_next_triangle_nber(n, idx);
        get_all_primes_factors_of_n(n, &primes, &primes_factors);
        if (get_divisors_count(&primes_factors) >= DIVISORS_NBER_LIMITE) {
            break;
        }

        gv_clear(&primes_factors, NULL);
    }

    printf("%ld\n", n);

    return 0;
}
