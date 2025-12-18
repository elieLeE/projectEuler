#include <stdio.h>
#include <stdbool.h>

/* We want to gets all values below MAX_N (1 000 000) that can be write with
 * form f(x, y, z) = x^2 - y^2 - z^2, with a natural integer z > 0 and
 * y = z + gap and x = y + gap, with gap a natural integer; > 0.
 * So, we have y = x - gap and x = y - gap.
 * By replacing y and z in f, we have
 * f(gap, x) = - x^2 + 6 * gap * x - 5 * gap^2.
 * By studying f according to x (gap fixed), we obtain
 * f'(gap, x) = -2 * x + 6 * gap and f'(gap, x) = 0 for x = 3 * gap.
 * We can see that for x < 3 * gap, f' > 0 and x > 3 * gap, f' < 0.
 * So, f increases for x in ]-inf, 3 * gap|] and decreases for x in
 * [|3 * gap, + inf[.
 * By studying f(gap, x) = 0, with gap fixed, we determine that the solution
 * are on gap and 5 * gap.
 * So, f >= 0 for x in [|gap, 5 * gap|] and < 0 elsewhere.
 * Moreover, it is easy to see that f is symmetrical per rapport an axe on
 * 3 * gap.
 * By compiling all these infos, we have to investigate, for a gap fixed, all
 * the values of x greater or equal to gap but lower or equal to 5 *gap.
 * And for all gap until a specific limit for this gap (that will detail
 * further).
 * It is important to see that x = z + 2 * gap. As the first value for z,
 * for all values of gap is 1, the first value of x has to be 1 + 2 * gap.
 * And then, x is increasing until 5 * gap.
 * But, we do not want to investigate the values of f greater than MAX_N
 * (1 000 000). So, we investigate all interesting values in 2 times.
 * First, all values for x in [[1 + 2 *gap, ...] until f(gap, x) becomes
 * greater than MAX_N. And the second time, for x in [(5 * gap, ...] until
 * f(gap, x) becomes greater than MAX_N. But, on the second time, x will be
 * decreasing !!
 * Finally, on which gap should we stop. About a certain value that depends on
 * gap value, f(gap, x) will never have a value between 0 and 1 000 000.
 * And, if we set gap0 the first value when that happens, all the f(gap, x)
 * with gap > gap0 will have the same property.
 * So, we stop on the first gap when no value of f(gap, x) has been found
 * between 0 and MAX_N. As g is symmetrical, this analysis can be done just
 * once. As, on the increasing x (so for x below 3 * gap), we start on
 * 1 + 2 * gap, the fact on not having found a f(gap, x) < MAX_N is not really
 * relevant. This analysis is done on the second time. So, we stop on the first
 * gap for which f(gap, (5 * gap) - 1) > 1 000 000. It is important to notice
 * that f(gap, 5 * gap) will always have the value 0 (cf above) !
 */
#define MAX_N 1000000

static long long f(long gap, long long x)
{
    return -x * x + 6 * x * gap - 5 * gap *gap;
}

int main(void)
{
    long sols_count[MAX_N] = {0};
    long long gap = 0;
    int res = 0;

    while (true) {
        long long x, sum, x_sum_max;

        gap++;
        x_sum_max = 3 * gap;
        x = 1 + 2 * gap;

        sum = f(gap, x);

        while (sum < MAX_N && x <= x_sum_max) {
            if (sum < 0) {
                break;
            } else if(sum >= 0) {
                sols_count[sum]++;
            }

            x++;
            sum = f(gap, x);
        }

        /* correspond to f(gap, 5 * gap) that will always return 0 */
        sols_count[0]++;

        x = (5 * gap) - 1;
        sum = f(gap, x);

        if (sum > MAX_N) {
            /* sum here is f(gap, (5 * gap) - 1). If it is greater than MAX_N,
             * it means that it is the end */
            break;
        }

        while (sum < MAX_N && x > x_sum_max) {
            sols_count[sum]++;

            x--;
            sum = f(gap, x);
        }
    }

    for (int i = 0; i < MAX_N; i++) {
        if (sols_count[i] == 10) {
            res++;
        }
    }

    printf("%d\n", res);

    return 0;
}
