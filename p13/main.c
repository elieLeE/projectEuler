#include <limits.h>

#include "../libC/src/io/io.h"
#include "../libC/src/macros.h"
#include "../libC/src/math/big_numbers.h"

generic_vector_t(bns, big_number_t);

static void free_bns_vector(void **_bn)
{
    big_number_t *bn = (big_number_t *)_bn;
    bn_wipe(bn);
}

static int read_numbers(gv_t(bns) *nbers)
{
    const unsigned int nbers_nb = 100;
    const unsigned int parts_nb = 5;
    const unsigned int size_part = 10;
    const unsigned long limit_part = 10000000000;

    FILE *f;
    char c;
    unsigned int number_counter = 1, digit_counter = 0;
    int part_counter = parts_nb - 1;
    unsigned long tmp = 0;
    big_number_t *bn;

    f = RETHROW_PN(ouv_fichier("numbers.txt", "r"));

    bn = gv_grow1(nbers);
    bn_init_with_args(bn, parts_nb, limit_part);

    while ((c = getc(f)) != EOF) {
        if (c < 48 || c > 57) {
            continue;
        }
        tmp += (c - '0');

        digit_counter++;
        if (digit_counter == size_part) {
            bn_set_part(bn, tmp, part_counter);

            part_counter--;

            if (part_counter < 0) {
                number_counter++;

                digit_counter = 0;
                part_counter = parts_nb - 1;

                if (number_counter > nbers_nb) {
                    break;
                }

                bn = gv_grow1(nbers);
                bn_init_with_args(bn, 5, limit_part);
            }
            digit_counter = 0;
            tmp = 0;
        } else {
            tmp *= 10;
        }
    }

   fermer_fichier(&f);

   return 0;
}

static void get_sum(const gv_t(bns) *in, big_number_t *out)
{
    bn_fast_clear(out);

    bn_set_limit(out, in->tab[0].limit);

     for (int i = 0; i < in->len; i++) {
        bn_add_bn(&(in->tab[i]), out, out);
     }
}

int main(void)
{
    gv_t(bns) nbers;
    big_number_t sum;
    char *sum_str;

     gv_init(&nbers);
     bn_init(&sum);

     if (read_numbers(&nbers) != 0) {
        printf ("error when reading numbers\n");
        return -1;
     }

     get_sum(&nbers, &sum);

     sum_str = bn_to_str(&sum);
     sum_str[11] = '\0';

     printf("%s\n", sum_str);

     p_free((void **)&sum_str);
     bn_wipe(&sum);
     gv_wipe(&nbers, free_bns_vector);

     return 0;
}
