/* In this problem, we want to determine the number 'N' below 1000 for which
 * the fraction 1/N will give the longest cycle.
 * Indeed, for these fractions, that can be exact, like 1/2 = 0,5 or not.
 * The no exact ones have a cycle. For example, 1/7 = 0,[142857], with the
 * numbers 1, 4, 2, 8, 5 and 7 repeating themselves in the same order
 * indefinitely.
 * The cycle is determined as below:
 * - we take 'X' the first 10 power greater than 'N'.
 * - we divide 'X' by 'N'. We obtain the quotient 'q' and the remainder 'res'.
 * - 'q' is the first number of the cycle. To get the next one, we repeat this
 *   operation with 'res' as 'N'. So we determine 'X' the first power greater
 *   then 'res'...
 * So, we will loop back when we will get res == N.
 * We do that in order to determine the cycle of the number.
 *
 * We can also notice that the longest cycle come from primes number (not all
 * will create long cycle but some of them will create the longest). I decided
 * to get the length of the cycle of odd numbers, as there is no even prime
 * number (expected 2 obviously).
 *
 * Finally, for a number 'N', the length maximal that we can have from it is
 * N - 1.
 * So, I start getting the length of the cycle from 1000. And if the number 'X'
 * has a cycle longer than every others number greater and this length is equal
 * to X - 1, we can automatically stop as the length maximal for all numbers
 * lower will X - 2.
 */

#include <stdio.h>

static int get_rec_cycle_fraction_len(int div)
{
    int n = 10;
    int len = 1;
    int first_res, res;

    while (n < div) {
        n *= 10;
    }
    res = first_res = n % div;

    do {
        res = (res * 10) % div;
        len++;
    } while (first_res != res); 

    return len - 1;
}

int main()
{
    int bigger_cycle_len = 0;
    int bigger_cycle_divisor = 0;

    for (int i = 999; i >= 2; i -= 2) {
        int current_cycle_len = get_rec_cycle_fraction_len(i);

        if (current_cycle_len > bigger_cycle_len) {
            bigger_cycle_len = current_cycle_len;
            bigger_cycle_divisor = i;

            if (current_cycle_len == i - 1) {
                break;
            }
        }
    }

    printf("%d\n", bigger_cycle_divisor);

    return 0;
}
