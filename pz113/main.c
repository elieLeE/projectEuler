#include <stdbool.h>
#include <stdio.h>

#define NBER_OF_DIGITS 100

/* The aim of this problem is to count of no bouncy numbers below 10^100,
 * with a bouncy number is a number that is no an increasing one neither
 * decreasing one (an increasing number has its digits that are never smaller
 * than the previous one (from left to right), same thing for decreasing
 * numbers but digits on left are always greater or equal than the one on its
 * right).
 * So, let' say the number abcd is an increasing one.
 * We know that for k between [1 - a], all kabcd will be an increasing number
 * too.
 * So, if we know the count of all N-digit increasing numbers starting from
 * [1 - 9], we know the count of all (N + 1)-digits increasing numbers from
 * [1 - 9].
 * It is given by the following formula Fd(n) = sum(d to 9)(fd(n-1))o
 *
 * Same reasoning can be done for decreasing numbers..
 */

unsigned long get_all_increasing_nbers_counter(void)
{
    unsigned long increasing_nbers_counter = 0;
    unsigned long increasing_nbers[NBER_OF_DIGITS][10] = {0};

    for (int i = 1; i < 10; i++) {
        increasing_nbers[0][i] = 1;
    }

    for (int i = 2; i <= NBER_OF_DIGITS; i++) {
        for (int j = 1; j < 10; j++) {
            unsigned long tmp = 0;

            for (int k = j; k < 10; k++) {
                tmp += increasing_nbers[i-2][k];
            }
            increasing_nbers[i-1][j] += tmp;
        }
    }

    for (int i = 0; i < NBER_OF_DIGITS; i++) {
        for (int j = 1; j < 10; j++) {
            increasing_nbers_counter += increasing_nbers[i][j];
        }
    }

    return increasing_nbers_counter;
}

unsigned long get_all_decreasing_nbers_counter(void)
{
    unsigned long decreasing_nbers[NBER_OF_DIGITS][10] = {0};
    unsigned long decreasing_nbers_counter = 0;

    for (int i = 1; i < 10; i++) {
        decreasing_nbers[0][i] = 1;
    }
    decreasing_nbers[0][0] = 1;

    for (int i = 2; i <= NBER_OF_DIGITS; i++) {
        for (int j = 9; j >= 0; j--) {
            unsigned long tmp = 0;

            for (int k = j; k >= 0; k--) {
                tmp += decreasing_nbers[i - 2][k];
            }
            decreasing_nbers[i-1][j] += tmp;
        }
    }

    for (int i = 0; i < NBER_OF_DIGITS; i++) {
        for (int j = 1; j < 10; j++) {
            decreasing_nbers_counter += decreasing_nbers[i][j];
        }
    }

    return decreasing_nbers_counter;
}

int main(void)
{
    unsigned long counter = 0;
    unsigned long increasing_nbers_counter = 0;
    unsigned long decreasing_nbers_counter = 0;

    /* got all NBER_OF_DIGITS-digits increasing numbers. This contains tooa the
     * numbers with this form aaaaaa, that means the number with always the
     * same digit. These numbers are decreasing numbers too. So, they are
     * counted twice.
     * Remove them from this counter and add then to the global count
     * (we could just remove them from only one of the two count but I think
     * it is clearer to remove them of the both count and then add them). */
    increasing_nbers_counter = get_all_increasing_nbers_counter();
    increasing_nbers_counter -= (9 * NBER_OF_DIGITS);

    decreasing_nbers_counter = get_all_decreasing_nbers_counter();
    decreasing_nbers_counter -= (9 * NBER_OF_DIGITS);

    counter = increasing_nbers_counter + decreasing_nbers_counter +
        (9 * NBER_OF_DIGITS);

    printf("%ld\n", counter);

    return 0;
}
