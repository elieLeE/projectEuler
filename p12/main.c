#include <stdio.h>
#include <string.h>

#include "../libC/src/math/nbre.h"
#include "../libC/src/math/prime.h"

#define DIVISORS_NBER_LIMITE 500

/* It is possible to demonstrate that the number of N is equal to the
 * multiplication of all the power of primes factors N.
 * So, if N = p1^a1 * p2^a2 * p3^a3...,
 * then N will have (a1 + 1) * (a2 + 1) * (a3 + 1)... divisors
 * (cf here: https://mathschallenge.net/index.php?section=faq&ref=number/number_of_divisors)
 */

void algo_1(void)
{
    unsigned int divisors_number = 0;
    unsigned long n = 1;
    unsigned long counter = 1;
    unsigned long primes[DIVISORS_NBER_LIMITE];
    prime_factor_t primes_factors[DIVISORS_NBER_LIMITE];

    if (get_all_n_first_primes(DIVISORS_NBER_LIMITE, DIVISORS_NBER_LIMITE,
                               primes) < 0)
    {
        return;
    }

    while (divisors_number < DIVISORS_NBER_LIMITE) {
        unsigned int count;
        unsigned int primes_factors_count;

        counter++;
        n = get_next_triangle_nber(n, counter);

        primes_factors_count =
            get_all_primes_factors_of_n(n, primes, DIVISORS_NBER_LIMITE,
                                        DIVISORS_NBER_LIMITE, primes_factors);

        count = get_divisors_count(primes_factors_count, primes_factors);

        if (count >= DIVISORS_NBER_LIMITE) {
            break;
        }

        memset(primes_factors, 0,
               sizeof(prime_factor_t) * primes_factors_count);
    }

    printf("%ld\n", n);
}

int main(void)
{
    algo_1();

    return 0;
}
