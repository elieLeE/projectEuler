#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/prime.h"

typedef struct rad_n_t {
    long n;
    long rad;
} rad_n_t;

generic_vector_t(rads_n, rad_n_t);

static int cmp_rad_n(const void *_rad1, const void *_rad2)
{
    const rad_n_t *rad1 = _rad1;
    const rad_n_t *rad2 = _rad2;

    if (rad1->rad != rad2->rad) {
        return rad1->rad - rad2->rad;
    }
    return rad1->n - rad2->n;
}

int main()
{
    const int limit = 100000;
    gv_t(uint64) primes;
    gv_t(primes_factors) primes_factors_n;
    gv_t(rads_n) rads_n;

    gv_init(&primes);
    gv_init(&primes_factors_n);
    gv_init(&rads_n);

    get_all_primes_below_n(limit, &primes);

    for (long n = 1; n <= limit; n++) {
        long rad = 1;
        rad_n_t rad_n = {.n = n};

        /* write a method to get primes factors of every number below n
         * more efficiently */
        get_all_primes_factors_of_n(n, &primes, &primes_factors_n);

        gv_for_each_pos(pos, &primes_factors_n) {
            rad *= primes_factors_n.tab[pos].prime;
        }
        rad_n.rad = rad;
        gv_insert_elem_sorted(&rads_n, rad_n, cmp_rad_n);

        gv_fast_clear(&primes_factors_n);
    }

    printf("%ld\n", rads_n.tab[10000 - 1].n);

    gv_wipe(&primes, NULL);
    gv_wipe(&primes_factors_n, NULL);
    gv_wipe(&rads_n, NULL);

    return 0;
}
