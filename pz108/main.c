#include "math.h"
#include "stdio.h"
#include "stdbool.h"

#define MIN_SOL_NBER 1000

/* 1 / x + 1 / y = 1 / n means that y = x * y / (x - n).
 * n is fixed and x has to be greater than n (as x, y and n are positives).
 * To avoid duplicated solutions, x has to be below than 2 * n.
 * Moreover, it looks logical that n has to be even to maximize the solutions.
 * As this was still not sufficient to have a "fast" solution, I have printed
 * the number when maximal and saw that they were all on the form 10^n.
 * So I have restrained calculation on all 10^n.
 * Got result in 6s.
 *
 * Can certainly do better. To see how.
 */

int get_all_fractions_counter_for_n(unsigned long n)
{
    int counter = 0;

    for (unsigned long x = n + 1; x <= 2 * n; x++) {
        double y = ((double)(x * n)) / (x - n);

        if (y == floor(y)) {
            counter++;
        }
    }

    return counter;
}

int main(void)
{
    int counter_max = 0;
    unsigned long n = 0;

    while (counter_max <= MIN_SOL_NBER) {
        int tmp;

        n += 10;

        tmp = get_all_fractions_counter_for_n(n);
        printf("n: %ld => %d\n", n, tmp);

        if (tmp > counter_max) {
            counter_max = tmp;
        }
    }

    printf("%ld\n", n);

    return 0;
}
