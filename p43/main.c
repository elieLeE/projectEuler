#include <stdio.h>
#include <stdbool.h>

#include "../libC/src/math/nber_helper.h"

#define NBRE_OF_DIGIT 10

/* Give the array of digits. All sub_n are on 3 digits, so it is just
 * necessary to give the address of the first digit.
 * Give the divisor too */
bool does_x_divide_sub_n(unsigned char digits[], unsigned int x)
{
    return (build_number_from_digits(digits, 0, 2) % x) == 0;
}

bool does_n_respect_the_property(unsigned char digits[NBRE_OF_DIGIT])
{
    /* Could add a static array to store all results in order to not re-do the
     * same calculation again. But the algorithm is enough fast */
    return does_x_divide_sub_n(&digits[1], 2) &&
        does_x_divide_sub_n(&digits[2], 3)    &&
        does_x_divide_sub_n(&digits[3], 5)    &&
        does_x_divide_sub_n(&digits[4], 7)    &&
        does_x_divide_sub_n(&digits[5], 11)   &&
        does_x_divide_sub_n(&digits[6], 13)   &&
        does_x_divide_sub_n(&digits[7], 17);
}

unsigned long
get_all_pandigitals_with_prop_sum_rec(unsigned char digits[NBRE_OF_DIGIT],
                                      bool digits_done[NBRE_OF_DIGIT],
                                      unsigned int depth)
{
    unsigned long long sum = 0;

    if (depth == NBRE_OF_DIGIT) {
        if (does_n_respect_the_property(digits)) {
            return build_number_from_digits(digits, 0, NBRE_OF_DIGIT - 1);
        }
        return 0;
    }

    for (unsigned int i = 0; i < NBRE_OF_DIGIT; i++) {
        if ((depth == 0) && (i == 0)) {
            continue;
        }

        if (digits_done[i]) {
            continue;
        }

        digits[depth] = i;
        digits_done[i] = true;

        sum += get_all_pandigitals_with_prop_sum_rec(digits, digits_done,
                                                     depth + 1);
        digits_done[i] = false;
    }

    return sum;
}

int main()
{
    unsigned char digits[NBRE_OF_DIGIT] = {0};
    bool digits_done[NBRE_OF_DIGIT] = {false};
    unsigned long long sum;

    sum = get_all_pandigitals_with_prop_sum_rec(digits, digits_done, 0);

    printf("%lld\n", sum);

    return 0;
}
