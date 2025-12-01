#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/nber_helper.h"

static int get_literal_length_digit_unities(int digit)
{
    switch(digit) {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 3;
    case 3:
        return 5;
    case 4:
        return 4;
    case 5:
        return 4;
    case 6:
        return 3;
    case 7:
        return 5;
    case 8:
        return 5;
    case 9:
        return 4;
    }

    logger_fatal("digit are always positive: %d\n", digit);
    return -1;
}

static int get_literal_length_digit_tens_below_twenty(int n)
{
    switch(n) {
    case 10:
        return 3;
    case 11:
        return 6;
    case 12:
        return 6;
    case 13:
        return 8;
    case 14:
        return 8;
    case 15:
        return 7;
    case 16:
        return 7;
    case 17:
        return 9;
    case 18:
        return 8;
    case 19:
        return 8;
    }

    logger_fatal("wrong value for n: %d\n", n);
    return -1;
}

static int get_literal_length_digit_tens(int digit)
{
    switch(digit) {
    case 0:
        return 0;
    case 1:
        logger_fatal("This case is handled by "
                     "'get_literal_length_digit_tens_below_twenty'\n");
        return -1;
    case 2:
        return 6;
    case 3:
        return 6;
    case 4:
        return 5;
    case 5:
        return 5;
    case 6:
        return 5;
    case 7:
        return 7;
    case 8:
        return 6;
    case 9:
        return 6;
    }

    logger_fatal("digit are always positive: %d\n", digit);
    return -1;
}

static int get_literal_length_digit(int digit, int pos)
{
    switch (pos) {
    case 0:
        return get_literal_length_digit_unities(digit);
    case 1:
        return get_literal_length_digit_tens(digit);
    case 2:
        if (digit == 0) {
            return 0;
        }
        return get_literal_length_digit_unities(digit) + 7;
    }

    logger_fatal("pos: %d seems wrong\n", pos);
    return -1;
}

/* This method works only for numbers below 1000 */
static int get_literal_length_n(int n)
{
    int count = 0;
    gv_t(uint8) digits;

    gv_init(&digits);

    get_digits_from_number(n, &digits);

    if (digits.len > 1 && digits.tab[1] == 1) {
        int tmp = digits.tab[1] * 10 + digits.tab[0];

        count += get_literal_length_digit_tens_below_twenty(tmp);
        if (digits.len == 3) {
            count += get_literal_length_digit(digits.tab[2], 2);
        }
    } else {
        gv_for_each_pos(pos, &digits) {
            count += get_literal_length_digit(digits.tab[pos], pos);
        }
    }

    if (digits.len == 3 && (digits.tab[0] != 0 || digits.tab[1] != 0)) {
        count += 3;
    }

    gv_wipe(&digits, NULL);

    return count;
}

int main()
{
    long count = 0;

    for (int i = 1; i < 1000; i++) {
        count += get_literal_length_n(i);
    }

    /* add length of '1000'. */
    count += 11;

    printf("%ld\n", count);

    return 0;
}
