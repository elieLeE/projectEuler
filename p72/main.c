#include <stdio.h>

#include "../libC/src/vector/vector.h"
#include "../libC/src/math/prime.h"

#define LIMITE_Y 1000000

int main(void)
{
    unsigned long counter = 0;
    gv_t(int64) phi_ns;

    gv_init_size(&phi_ns, LIMITE_Y);

    get_all_phi_from_1_to_n(LIMITE_Y, &phi_ns);

    gv_for_each_pos(pos, &phi_ns) {
        counter += phi_ns.tab[pos];
    }

    /* remove value for 1 */
    counter--;
    printf("%ld\n", counter);

    gv_wipe(&phi_ns, NULL);

    return 0;
}
