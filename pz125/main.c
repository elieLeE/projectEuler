#include <stdio.h>
#include <math.h>

#include "../libC/src/math/calculs.h"
#include "../libC/src/math/nber_helper.h"
#include "../libC/src/utils.h"

int main(void)
{
    const long limit = pow(10, 8);
    const long limit_sqrt = sqrt(limit);
    long res = 0;
    gv_t(int64) numbers_found;

    gv_init(&numbers_found);

    for (long i = 1; i <= limit_sqrt; i++) {
        long squares_to_remove = sum_carre_1_to_n(i - 1);

        for (long j = i + 1; j <= limit_sqrt; j++) {
            long n = sum_carre_1_to_n(j) - squares_to_remove;

            if (n > limit) {
                break;
            }

            if (is_nber_a_palindrome(n)) {
                /* Use qhash here when it will be implemented !! */
                if (!(gv_contains(&numbers_found, n, GV_DICHOTOMY_SEARCH,
                                 g_cmp_int64)))
                {
                    gv_insert_elem_sorted(&numbers_found, n, g_cmp_int64);
                    res += n;
                }
            }
        }
    }

    gv_wipe(&numbers_found, NULL);

    printf("%ld\n", res);

    return 0;
}
