#include <stdio.h>

#define SUM_TRIPLET 1000

int main(void)
{
    unsigned long res = 0;

    for (unsigned int a = 1; a < SUM_TRIPLET / 2; a++) {
        unsigned int square_a = a * a;

        for (unsigned int b = a; b < SUM_TRIPLET / 2; b++) {
            unsigned c = SUM_TRIPLET - a - b;

            if (square_a + b * b == c * c) {
                res = a * b * c;
                break;
            }
        }
        if (res != 0) {
            break;
        }
    }

    printf("%ld\n", res);

    return 0;
}
