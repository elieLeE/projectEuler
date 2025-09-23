#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <gmp.h>

#define LIMITE 10000
#define TAILLE_TAB 7

int get_sqrt_period(int n)
{
    double sqrt_n;
    int x;
    int period = 0;

    sqrt_n = sqrt(n);
    x = floor(sqrt_n);

    /* n is a perfect square => no period */
    if (x != sqrt_n) {
        int num = 1;
        int denum, first_num, first_denum;

        first_num = num;
        first_denum = denum = -x;

        /* As the numerator and denominator are respectively different from
         * the first numerator and the first denominator, we do not have reach
         * to the end of the period, and so we continue. */
        do {
            int tmp;

            x = floor(num / (sqrt_n + denum));
            tmp = n - denum * denum;

            if (num != 1) {
                tmp = tmp / num;
                num = 1;
            }

            denum = - (num * denum + x * tmp);
            num = tmp;
            period++;
        } while((first_num != num) | (first_denum != denum));
    }

    return period;
}

int main()
{
    int compt = 0, i;

    for (i = 2; i <= LIMITE; i++) {
        int period = get_sqrt_period(i);

        if (period % 2 != 0) {
            compt++;
        }
    }
    printf("%d\n", compt);

    return 0;
}
