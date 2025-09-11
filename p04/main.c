#include <stdio.h>

#include "../libC/src/math/nbre.h"

int main()
{
    unsigned int n = 101, max_palindrome = 0;
    unsigned int x, m;

    while (n < 1000) {
        m = n + 1;

        while (m < 1000) {
            x = n * m;

            if (is_nber_a_palindrome(x)) {
                if (x > max_palindrome) {
                    max_palindrome = x;
                }
            }
            m++;
        }
        n++;
    }

    printf("%d\n", max_palindrome);
    return 0;
}

