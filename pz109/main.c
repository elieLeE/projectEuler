#include <stdbool.h>
#include <stdio.h>

#define SKIP_LOG 1

bool can_finish(int n)
{
    return (n == 50) || (n >= 2 && n <= 40 && (n % 2) == 0);
}

int get_all_checkout_poss_rec(int n, int depth, int min_simple,
                              int min_double, int min_triple)
{
    int count = 0;

    if (can_finish(n)) {
        count++;
    }

    if (depth == 3) {
        return count;
    }

    if (depth == 1 && n >= 27) {
        count += get_all_checkout_poss_rec(n - 25, depth + 1, 1, 1, 1);

        if (n >= 52) {
            count += get_all_checkout_poss_rec(n - 50, depth + 1, 1, 1, 1);
            count += get_all_checkout_poss_rec(n - 50, 3, 1, 1, 1);
        }

        if (n >= 77) {
            count += get_all_checkout_poss_rec(n - 75, 3, 1, 1, 1);
        }
    }

    for (int t = min_triple; n - t * 3 >= 2 && t <= 20; t++) {
        count += get_all_checkout_poss_rec(n - t * 3, depth + 1, n, 1, t);
    }

    for (int d = min_double; n - d * 2 >= 2 && d <= 20; d++) {
        count += get_all_checkout_poss_rec(n - d * 2, depth + 1, n, d, n);
    }

    for (int s = min_simple; n - s >= 2 && s <= 20; s++) {
        count += get_all_checkout_poss_rec(n - s, depth + 1, s, 1, 1);
    }

    return count;
}

int main(void)
{
    int count = 0;

    for (int i = 2; i < 100; i++) {
        count += get_all_checkout_poss_rec(i, 1, 1, 1, 1);
    }

    printf("%d\n", count);

    return 0;
}
