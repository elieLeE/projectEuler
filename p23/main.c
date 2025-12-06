#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/prime.h"

#define LIMIT 28124

int main()
{
    unsigned long res = 0;
    gv_t(uint64) primes;
    gv_t(uint64) abundant_nbers;
    bool two_abundant_nbers_sum[LIMIT] = {false};

    gv_init(&primes);
    gv_init(&abundant_nbers);

    get_all_primes_below_n(LIMIT, &primes);

    for (unsigned long i = 2; i < LIMIT; i++) {
        unsigned long divisors_sum;

        divisors_sum = get_proper_divisors_sum_of_n(i, &primes);

        if (divisors_sum > i) {
            gv_add(&abundant_nbers, i);
        }
    }

    gv_for_each_pos(pos, &abundant_nbers) {
        unsigned long tmp = abundant_nbers.tab[pos];

        for (int pos2 = pos; pos2 < abundant_nbers.len; pos2++) {
            unsigned long tmp2 = tmp + abundant_nbers.tab[pos2];

            if (tmp2 < LIMIT) {
                two_abundant_nbers_sum[tmp2] = true;
            }
        }
    }

    for (int i = 0; i < LIMIT; i++) {
        if (!two_abundant_nbers_sum[i]) {
            res += i;
        }
    }

    gv_wipe(&primes, NULL);
    gv_wipe(&abundant_nbers, NULL);

    printf("%ld\n", res);

    return 0;
}
