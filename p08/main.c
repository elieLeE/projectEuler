#include "../libC/src/io/io.h"

#define DIGITS_NBER 1000
#define DIGITS_NBER_PRODUCT 13

int read_digits(unsigned char digits[DIGITS_NBER])
{
    FILE *f = ouv_fichier("1000_digits.txt", "r");
    int c;
    unsigned index = 0;

    if (f == NULL) {
        return -1;
    }
    while ((c = getc(f)) != EOF) {
        if (c < 48 || c > 57) {
            continue;
        }
        /* Here, the digit have the values like these '0', '1', ...
         * We want them to have these value 0, 1... */
        digits[index] = ((unsigned char)c) - '0';
        index++;
    }

   fermer_fichier(&f);

   return 0;
}

unsigned long get_max_product(unsigned char digits[DIGITS_NBER])
{
    unsigned long max = 1;

    for (unsigned int i = 0; i < DIGITS_NBER - DIGITS_NBER_PRODUCT + 1; i++) {
        unsigned long tmp = 1;

        for (unsigned int j = i; j < i + DIGITS_NBER_PRODUCT; j++) {
            if (digits[j] == '0') {
                i = j + 1;
                break;
            }
            tmp = tmp * digits[j];
        }
        if (tmp > max) {
            max = tmp;
        }
    }

    return max;
}

int main(void)
{
    unsigned char digits[DIGITS_NBER];

    if (read_digits(digits) == 0) {
        printf("%ld\n", get_max_product(digits));
    }

    return 0;
}
