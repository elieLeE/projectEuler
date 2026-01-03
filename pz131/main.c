#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/prime.h"
#include "../libC/src/utils.h"

/* We have f(n, p) = n³ + n² * p = n² * (n + p).
 * By observation, I have seen that for having f(n) a perfect cube, it is
 * necessary that n and n + p be perfect cube (it is probably possible to
 * demonstrate it. Me, I have discovered by observing the results on "small"
 * results.
 * So, n and n + p are perfect cube equals to p has to be a difference of two
 * perfect cubes.
 * We fill all the cubes below the limit and look for all the primes equal
 * to the difference of cubes. And that is. */

int main()
{
    const unsigned int limit = 1000000;
    unsigned int count = 0;
    gv_t(uint64) primes;
    gv_t(uint64) cubes;

    gv_init(&primes);
    gv_init(&cubes);

    get_all_primes_below_n(limit, &primes);

    for (unsigned long i = 1; i < 2 * limit; i++) {
        gv_add(&cubes, i * i * i);
    }

    gv_for_each_pos(pos, &cubes) {
        long cube = cubes.tab[pos];

        for (long pos2 = pos + 1; pos2 < cubes.len; pos2++) {
            long p = cubes.tab[pos2] - cube;

            if (p > limit) {
                break;
            }

            if (gv_contains(&primes, p, GV_DICHOTOMY_SEARCH, g_cmp_uint64)) {
                count++;
                break;
            }
        }
    }

    gv_wipe(&cubes, NULL);
    gv_wipe(&primes, NULL);

    printf("%d\n", count);

    return 0;
}
