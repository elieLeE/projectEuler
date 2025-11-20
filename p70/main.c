#include "../libC/src/math/nber_helper.h"
#include "../libC/src/math/prime.h"

#define LIMITE 10000000

int main()
{
    int n;
    gv_t(int64) phi_n;
    unsigned int best_n;
    double quotient_min = (double)LIMITE;

    n = best_n = LIMITE;

    /* In the algo of the function phi, we only take the prime number.
     * Moreover, if we have a number n, p one of its divisors and q the
     * associated divisor, then either p or q are less than or equal to n.
     * So, we just need to get all primes less then or equal the square of n.
     * */
    gv_init_size(&phi_n, LIMITE);

    get_all_phi_from_1_to_n(LIMITE, &phi_n);

    /* We want to maximize the quotient n / phi(n). So, we want to maximize
     * phi(n). As any even number will have, at maximum, n/2 relatively prime
     * number (in fact much less than that), we can skip them */
    if (n % 2 == 0) {
        n--;
    }

    while (n >= 3) {
        double quotient;

        /* for any number, the way to maximize n / phi(n) is when n is a prime
         * number. Indeed, if n is a prime number, then phi(n) = n-1. But, n
         * and n-1 will be never permutations from each other. So, we try with
         * numbers that are only the product of two prime numbers. */
        quotient = ((double)n) / (phi_n.tab[n]);
        //printf("n: %d, phi_n: %d, quotient: %f\n", n, phi_n, quotient);

        if (are_permutation_nbers(n, phi_n.tab[n])) {
            if (quotient < quotient_min) {
                quotient_min = quotient;
                best_n = n;
            }
        }
        n -= 2;
    }

    gv_wipe(&phi_n, NULL);

    printf("%d\n", best_n);
}
