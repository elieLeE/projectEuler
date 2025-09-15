#include <stdio.h>
#include <string.h>
#include <math.h>
#include "limits.h"

#include "../libC/src/math/prime.h"

#define MAX_DIVISOR 20

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
    unsigned long all_primes[MAX_DIVISOR] = {0};
    unsigned int primes_nber_found = 0;
    unsigned int primes_factors_found = 0;
    /* all primes factors of all number below MAX_DIVISOR */
    prime_factor_t all_primes_factors[MAX_DIVISOR];
    unsigned int answer = 1;

    memset(all_primes_factors, 0, MAX_DIVISOR * sizeof(prime_factor_t));

    primes_nber_found =
        get_all_primes_below_n(MAX_DIVISOR, MAX_DIVISOR, all_primes);

    for (unsigned int i = 2; i <= MAX_DIVISOR; i++) {
        prime_factor_t current_primes_factors[MAX_DIVISOR] = {0};
        unsigned int primes_factors_counter;

        primes_factors_counter =
            get_all_primes_factors_of_n(i, all_primes, primes_nber_found + 1,
                                        MAX_DIVISOR, current_primes_factors);

        for (unsigned int j = 0; j < primes_factors_counter; j++) {
            prime_factor_t *tmp = NULL;

            for (unsigned int k = 0; k < primes_factors_found; k++) {
                if (current_primes_factors[j].prime ==
                    all_primes_factors[k].prime)
                {
                    tmp = &all_primes_factors[k];

                    if (current_primes_factors[j].iteration > tmp->iteration) {
                        tmp->iteration = current_primes_factors[j].iteration;
                    }
                    break;
                }
            }
            /* the prime factor has not been found. we add it. */
            if (tmp == NULL) {
                all_primes_factors[primes_factors_found] =
                    current_primes_factors[j];
                primes_factors_found++;
            }
        }
    }

    for (unsigned int i = 0; i < MAX_DIVISOR; i++) {
        answer = answer * pow(all_primes_factors[i].prime,
                              all_primes_factors[i].iteration);
    }

    printf("%d\n", answer);

    return 0;
}

