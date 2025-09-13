#include <stdio.h>

#include "../libC/src/math/prime.h"
#include "../libC/src/math/nbre.h"

/* Create recursively all pandigitals numbers from 987654321 to the 12 until
 * one of them is a prime */
static int
search_pandigital_prime_nber_rec(unsigned char digits[10],
                                 bool digits_done[10],
                                 int depth, int last_digit)
{
    if (depth == last_digit) {
        unsigned long n = build_number_from_digits(digits, 0, last_digit);

        return is_prime(n) ? 0 : -1;
    }

    for (int i = last_digit; i > 0; i--) {
        if (digits_done[i]) {
            continue;
        }

        digits[depth] = i;
        digits_done[i] = true;

        if (search_pandigital_prime_nber_rec(digits, digits_done,
                                             depth + 1, last_digit) == 0)
        {
            return 0;
        }
        digits_done[i] = false;
    }

    return -1;
}

static int
search_pandigital_prime_nber(unsigned char digits[10], int last_digit)
{
    bool digits_done[10] = {false};

    for (int i = last_digit + 1; i < 10; i++) {
        digits_done[i] = true;
    }

    return
        search_pandigital_prime_nber_rec(digits, digits_done, 0, last_digit);
}

int main()
{
    for (int i = 9; i > 0; i--) {
        unsigned char digits[10] = {0};

        if (search_pandigital_prime_nber(digits, i) == 0) {
            printf("%ld\n", build_number_from_digits(digits, 0, i));

            break;
        }
    }

    return 0;
}
