#include <math.h>
#include "../libC/src/math/nbre.h"
#include "../libC/src/math/prime.h"
#include "../libC/src/mem/mem.h"

#define LIMITE 10000000

int main()
{
    int n;
    unsigned int *primes_nber;
    unsigned int best_n;
    unsigned int idx_max;
    double quotient_min = (double)LIMITE;
    unsigned int limite_prime;

    n = best_n = LIMITE;

    /* In the algo of the function phi, we only take the prime number.
     * Moreover, if we have a number n, p one of its divisors and q the
     * associated divisor, then either p or q are less than or equal to n.
     * So, we just need to get all primes less then or equal the square of n.
     * */
    limite_prime = floor(sqrt(LIMITE)) + 1;
    primes_nber = p_calloc(sizeof(int) * limite_prime);
    idx_max = remplissage_tab_prime(primes_nber, limite_prime);

    /* We want to maximize the quotient n / phi(n). So, we want to maximize
     * phi(n). As any even number will have, at maximum, n/2 relatively prime
     * number (in fact much less than that), we can skip them */
    if (n  % 2 == 0) {
        n--;
    }

    while (n >= 3) {
        double quotient;
        unsigned int phi_n;

        /* for any number, the way to maximize n / phi(n) is when n is a prime
         * number. Indeed, if n is a prime number, then phi(n) = n-1. But, n
         * and n-1 will be never permutations from each other. So, we try with
         * numbers that are only the product of two prime numbers. */
        phi_n = get_phi(n, primes_nber, idx_max, true);
        quotient = ((double)n) / ((double)phi_n);

        if (are_permutation_nbers(n, phi_n)) {
            if (quotient < quotient_min) {
                quotient_min = quotient;
                best_n = n;
            }
        }
        n -= 2;
    }

    printf("n: %d\n", best_n);
}
