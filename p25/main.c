#include <stdio.h>

#include "../libC/src/math/nber_helper.h"
#include "../libC/src/math/big_numbers.h"

int main(void)
{
    unsigned long index = 3;    
    unsigned int digits_count = 1;
    big_number_t n1, n2, n3;

    bn_init(&n1);
    bn_init(&n2);
    bn_init(&n3);

    bn_set_from_ul(1, &n2);
    bn_set_from_ul(2, &n3);

    while (digits_count < 1000) {
        bn_set_from_bn(&n2, &n1);
        bn_set_from_bn(&n3, &n2);

        bn_add_bn(&n1, &n2, &n3);

        digits_count = bn_get_digits_count(&n3);

        index++;
    }

    bn_wipe(&n1);
    bn_wipe(&n2);
    bn_wipe(&n3);

    printf("%ld\n", index);

    return 0;
}
