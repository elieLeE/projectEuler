#include <stdio.h>

#define LIMITE 4000000

int main()
{
    unsigned int f1 = 0, f2 = 1, f3 = 0;
    unsigned int sum = 0;

    while(f3 < LIMITE) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;

        if(f3 % 2 == 0) {
            sum = sum + f3;
        }
    }

    printf("%d\n", sum);

    return 0;
}


