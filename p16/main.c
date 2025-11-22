#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/nber_helper.h"

#define POWER 1000
#define LIMIT 100000000000000000

int main(void)
{
    /* From a certain idx, 2^X is just to big to be stocked in a variable.
     * I could use mpz library but I do not think that the spirit. */
    gv_t(uint64) n;
    gv_t(uint8) digits;
    unsigned long sum = 0;

    gv_init(&n);
    gv_init(&digits);

    gv_add(&n, 2);

    for (int i = 2; i <= POWER; i++) {
        int carry = 0;

        gv_for_each_pos(pos, &n) {
            unsigned long tmp = n.tab[pos] * 2 + carry;

            carry = 0;
            if (tmp > LIMIT) {
                carry = tmp / LIMIT;
                tmp -= LIMIT * carry;
            }

            n.tab[pos] = tmp;
        }

        if (carry != 0) {
            gv_add(&n, carry);
        }
    }

    gv_for_each_pos(pos, &n) {
        get_digits_from_number(n.tab[pos], &digits);
    }

    gv_for_each_pos(pos, &digits) {
        sum += digits.tab[pos];
    }
    printf("%ld\n", sum);

    gv_wipe(&n, NULL);
    gv_wipe(&digits, NULL);

    return 0;
}
