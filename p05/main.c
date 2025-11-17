#include <stdio.h>
#include <string.h>
#include <math.h>
#include "limits.h"

#include "../libC/src/math/prime.h"
#include "../libC/src/vector/vector.h"

#define MAX_DIVISOR 20

static int cmp_primes_factors(const void *_pf1, const void *_pf2)
{
    const prime_factor_t *pf1 = _pf1;
    const prime_factor_t *pf2 = _pf2;

    return pf1->prime - pf2->prime;
}

/* To resolve this problem, it is important to see that if p divide n, that
 * means all the primes factors multiplied by theirs iterations divide n.
 * So, for all numbers from 1 to N, we can get all theirs primes factors,
 * keeping the iterations maximal for all of them.
 * The, we just need to multiply all these primes factors by themselves and
 * together to finally determine the first number to be divided by all number
 * from 1 to N */
int main()
{
    /* all primes number below MAX_DIVISOR */
    gv_t(uint64) primes;
    /* all primes factors of all number below MAX_DIVISOR */
    gv_t(primes_factors) all_primes_factors;
    gv_t(primes_factors) current_primes_factors;

    unsigned int answer = 1;

    gv_init(&primes);
    gv_init(&all_primes_factors);
    gv_init(&current_primes_factors);

    get_all_primes_below_n(MAX_DIVISOR, &primes);

    for (unsigned int i = 2; i <= MAX_DIVISOR; i++) {
        get_all_primes_factors_of_n(i, &primes, &current_primes_factors);

        gv_for_each_pos(pos, &current_primes_factors) {
            int pos2;
            prime_factor_t *tmp = NULL;
            prime_factor_t *current_prime_factor = NULL;

            current_prime_factor = &(current_primes_factors.tab[pos]);

            pos2 = gv_find(&all_primes_factors, *current_prime_factor,
                           cmp_primes_factors);

            if (pos2 != -1) {
                tmp = &(all_primes_factors.tab[pos2]);
                if (current_prime_factor->iteration > tmp->iteration) {
                    tmp->iteration = current_prime_factor->iteration;
                }
            } else {
                /* the prime factor has not been found. We add it. */
                gv_add(&all_primes_factors, *current_prime_factor);
            }
        }
        gv_clear(&current_primes_factors, NULL);
    }

    gv_for_each_pos(pos, &all_primes_factors) {
        answer = answer * pow(all_primes_factors.tab[pos].prime,
                              all_primes_factors.tab[pos].iteration);
    }

    printf("%d\n", answer);

    gv_wipe(&primes, NULL);
    gv_wipe(&all_primes_factors, NULL);
    gv_wipe(&current_primes_factors, NULL);

    return 0;
}

