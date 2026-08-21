#include <stdio.h>

#include "../libC/src/math/nber_helper.h"
#include "../libC/src/math/big_numbers.h"

int main(void)
{
    big_number_t n;
    unsigned long sum = 0;

    bn_init_multiplying(&n);

    bn_get_fact_n(100, &n);
    sum = bn_get_digits_sum(&n);

    printf("%ld\n", sum);

    bn_wipe(&n);

    return 0;
}
