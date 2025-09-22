#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "../libC/src/math/nbre.h"
#include "../libC/src/macros.h"
#include "../libC/src/mem/mem.h"

#define PERCENTAGE_STOP 99.0

int search_bouncy_limits_nber_rec(unsigned char digits[],
                                  int depth, int max_depth,
                                  unsigned int *bouncy_counter,
                                  unsigned int *total_nber_counter)
{
    if (is_a_bouncy_number(digits, depth - 1)) {
        double per;
        unsigned int tmp, bouncy_counter_tmp, total_nber_counter_tmp;

        /* if a part of the number (and here the beginning) is bouncy, all the
         * number building from this one will be bouncy.
         * For example, if we have a 5 digits number and here the three first
         * digits are '132'. Then, whatever is added after this three digits,
         * all the numbers will be bouncy ones.So, we can just count how many
         * numbers can be generated from this basis and add this count to the
         * bouncy counter */
        tmp = pow(10, max_depth - depth);
        bouncy_counter_tmp = (*bouncy_counter) + tmp;
        total_nber_counter_tmp = (*total_nber_counter) + tmp;

        per = PERCENTAGE((bouncy_counter_tmp), (total_nber_counter_tmp));

        /* We are looking for the number when the percentage will be exactly
         * equal to PERCENTAGE_STOP. if per < PERCENTAGE_STOP, so, we can just
         * reset the 'bouncy_counter' and 'total_nber_counter' and continue. */
        if (per < PERCENTAGE_STOP) {
            *bouncy_counter = bouncy_counter_tmp;
            *total_nber_counter = total_nber_counter_tmp;

            return -1;
        } else if (per == PERCENTAGE_STOP && depth == max_depth) {
            return 0;
        }
    } else if (depth == max_depth) {
        (*total_nber_counter)++;

        return -1;
    }

    for (unsigned char i = 0; i <= 9; i++) {
        int res;

        digits[depth] = i;

        res = search_bouncy_limits_nber_rec(digits, depth + 1, max_depth,
                                            bouncy_counter,
                                            total_nber_counter);

        if (res == 0) {
            return 0;
        }
        digits[depth] = 0;
    }

    return -1;
}

int main(void)
{
    unsigned char *digits;
    unsigned int nber_of_digits = 1;
    unsigned int bouncy_counter = 0, total_nber_counter = 0;
    unsigned long n = 0;

    while (n == 0) {
        int res;

        digits = p_calloc(nber_of_digits);

        for (unsigned char i = 1; i <= 9; i++) {
            digits[0] = i;

            res = search_bouncy_limits_nber_rec(digits, 1, nber_of_digits,
                                                &bouncy_counter,
                                                &total_nber_counter);
            if (res == 0) {
                n = build_number_from_digits(digits, 0, nber_of_digits - 1);
                break;
            }
        }

        nber_of_digits++;

        p_free((void **)&digits);
    }

    printf("%ld\n", n);

    return 0;
}
