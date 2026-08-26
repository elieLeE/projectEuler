#include <stdio.h>

#include "../libC/src/math/big_numbers.h"

#define POWER 1000
#define LIMIT 100000000000000000

int main(void)
{
    /* From a certain idx, 2^X is just to big to be stocked in a variable.
     * I could use mpz library but I do not think that the spirit. */
    big_number_t n;
    unsigned long sum = 0;

    bn_init_multiplying(&n);

    bn_ul_pow_ul(2, 1000, &n);
    sum = bn_get_digits_sum(&n);

    printf("%ld\n", sum);

    bn_wipe(&n);

    return 0;
}
