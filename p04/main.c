#include <stdio.h>
#include <stdbool.h>

unsigned int nbre_to_tab(char *tab, unsigned int n)
{
    unsigned int n2;
    unsigned int i = 0;
    char d;

    while (n >= 1) {
        n2 = n / 10;
        d = n - n2 * 10;
        tab[i] = d;
        n = n2;
        i++;
    }
    return i;
}

bool is_palindrome(unsigned int n)
{
    static char tab_digit[6];
    unsigned int nbre_digits;

    nbre_digits = nbre_to_tab(tab_digit, n);

    for (unsigned int i = 0; i<nbre_digits / 2; i++) {
        if (tab_digit[i] != tab_digit[nbre_digits - i - 1]) {
            return false;
        }
    }

    return true;
}

int main()
{
    unsigned int n = 101, max_palindrome = 0;
    unsigned int x, m;

    while (n < 1000) {
        m = n + 1;

        while (m < 1000) {
            x = n * m;

            if (is_palindrome(x)) {
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

