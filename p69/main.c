#include <stdio.h>
#include <assert.h>

#include "../libC/src/math/prime.h"

#define LIMITE 1000000

int main()
{
    int n;
    double quotient_max = 0.0;
    gv_t(int64) phi_n;

    gv_init_size(&phi_n, LIMITE);

    get_all_phi_from_1_to_n(LIMITE, &phi_n);

    gv_for_each_pos(pos, &phi_n) {
        double quotient;

        quotient = ((double)pos) / phi_n.tab[pos];

        if (quotient > quotient_max) {
            quotient_max = quotient;
            n = pos;
        }
    }
    printf("%d\n", n);

    gv_wipe(&phi_n, NULL);

    return 0;
}
