#include <stdio.h>
#include <math.h>

/* For a power N, count how many numbers can be generated that have N digits.
 * So, as the numbers have to have N digits, that means all the numbers that
 * will be found will included between 10^(N - 1) and 10^N. Indeed,
 * 10^(N - 1) have N digits and it is the lowest number with N digits.
 */

unsigned int get_numbers_power_count(int power)
{
    unsigned int i = 1, compt = 0;
    double limit_low = pow(10, power - 1);
    double limit_up = limit_low * 10;
    double calcul = 0;

    while ((calcul = pow(i, power)) < limit_up) {
        if (calcul >= limit_low) {
            compt++;
        }
        i++;
    }
    return compt;
}

/* We stop when get_numbers_power_count return 0.
 * That means the power N is so important that the numbers generated will
 * skipped all the N-digits numbers. If it has happens for the power N,
 * it will happen to the power greater than N. */
int main()
{
    unsigned int compt = 0, i = 1;
    int tmp;

    do {
        tmp = get_numbers_power_count(i);
        compt += tmp;
        i++;
    } while (tmp != 0);

    printf("%d\n", compt);

    return 0;
}
