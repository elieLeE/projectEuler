#include <stdio.h>

#include "../libC/src/vector/vector.h"

#define LIMIT 1000000

unsigned long get_next_term(unsigned long n)
{
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

void fill_seq_size_values(unsigned long n, gv_t(uint64) *seq_sizes,
                          gv_t(uint64) *intermediates_term)
{
    unsigned long seq_size = 0;

    do {
        seq_size++;

        gv_add(intermediates_term, n);
        n = get_next_term(n);
    } while (n != 1);

    gv_for_each_pos(pos, intermediates_term) {
        unsigned long term = intermediates_term->tab[pos];

        if (term < LIMIT) {
            seq_sizes->tab[term] = seq_size - pos;
        }
    }
}

int main(void)
{
    gv_t(uint64) seq_sizes;
    gv_t(uint64) intermediates_term;
    unsigned long max_seq_size = 1;
    int max_seq_size_n;

    gv_init_size(&seq_sizes, LIMIT + 1);
    gv_init(&intermediates_term);

    /* It looks logical that an odd number should have a longer sequence that
     * an equivalent even number, but doe that happens really systematically ??
     */
    for (unsigned long i = 3; i < LIMIT; i++) {
        if (seq_sizes.tab[i] == 0) {
            fill_seq_size_values(i, &seq_sizes, &intermediates_term);

            gv_clear(&intermediates_term, NULL);
        }
    }

    for (int i = 2; i < LIMIT; i++) {
        if (seq_sizes.tab[i] > max_seq_size) {
            max_seq_size = seq_sizes.tab[i];
            max_seq_size_n = i;
        }
    }

    printf("%d\n", max_seq_size_n);

    gv_wipe(&intermediates_term, NULL);
    gv_wipe(&seq_sizes, NULL);

    return 0;
}
