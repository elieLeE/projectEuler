#include <stdio.h>
#include <string.h>

#include "../libC/src/math/nber_helper.h"

static bool can_become_a_pandigital(unsigned int nbre)
{
    unsigned int n = nbre, nbre_digits = 0, total_nber_digits = 0;
    unsigned char all_digits[10] = {0};

    while (true) {
        nbre_digits = get_digits_iterations_from_number(n, all_digits);
        total_nber_digits += nbre_digits;

        if (all_digits[0] > 0) {
            return false;
        }

        for (unsigned int i = 1; i <= total_nber_digits; i++) {
            if (all_digits[i] > 1) {
                return false;
            }
        }

        if (total_nber_digits == 9) {
            return true;
        }

        n += nbre;
    }
}

static unsigned long get_pandigital_nber_from_n(int n)
{
    unsigned int nbre_digits = 0;
    unsigned int total_nber_digits = 0;
    unsigned char all_digits[10] = {0};

    while (true) {
        unsigned char current_digits[10] = {0};

        nbre_digits = get_digits_from_number(n, current_digits);

        total_nber_digits += nbre_digits;
        if (total_nber_digits <= 9) {
            memcpy(&all_digits[9 - total_nber_digits], current_digits,
                   nbre_digits);
        }

        if (total_nber_digits >= 9) {
            break;
        }
        n += n;
    }

    return build_number_from_digits_rev(all_digits, 0, 9);
}

int main(void)
{
    /* We have to concatenate 2 numbers in order to form a 9-digit member.
     * So, maximum of the basic number has to have less than 5 digits as all
     * 5-digits number product will have at least 5 digits and so the
     * concatenations of the number will overtake the maximum of 9 digits */
    int n = 10000;

    /* Determine if the number n, with the concatenation of its multiple,
     * can become a pandigital number. If yes, stop and display this pandigital
     * number. */
    while (true){
        if (can_become_a_pandigital(n)) {
            break;
        }
        n--;
    }

    printf("%ld\n", get_pandigital_nber_from_n(n));

}
