#include <stdio.h>
#include <stdbool.h>

static bool
is_triangle_rectangle(unsigned int a, unsigned int b, unsigned int c)
{
    return (a * a + b * b == c * c);
}

static int get_triangle_rect_nber(unsigned int p)
{
    unsigned int k, compt = 0;

    for (unsigned int i = 1; i < p/2; i++) {
        for (unsigned int j = i + 1; j < p/2; j++) {
            k = p - i - j;

            if ((i + j > k) && is_triangle_rectangle(i, j, k)) {
                compt++;
            }
        }
    }
    return compt;
}

int main(void)
{
    unsigned int count_max = 0;
    unsigned int answer;

    for (unsigned int i = 3; i <= 1000; i++) {
        unsigned int count = get_triangle_rect_nber(i);

        if (count > count_max) {
            count_max = count;
            answer=i;
        }
    }

    printf("%d\n", answer);

    return 0;
}
