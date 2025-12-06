#include "../libC/src/io/io.h"
#include "../libC/src/macros.h"

#define SIDE_LENGTH 20
#define NBER_COUNT SIDE_LENGTH * SIDE_LENGTH
#define NBER_PRODUCT_COUNT 4
/* In several times in the method below, we need to stop at the first index
 * before having less than 4 numbers to the end (as we are looking for the
 * product maximum of four numbers) */
#define COMMON_INDEX_MAX SIDE_LENGTH - NBER_PRODUCT_COUNT + 1

static int read_numbers(unsigned int nbers[SIDE_LENGTH][SIDE_LENGTH])
{
    FILE *f;
    int c;
    unsigned index_lig = 0, index_col = 0;

    f = RETHROW_PN(ouv_fichier("grid.txt", "r"));

    while ((c = fscanf(f, "%d", &nbers[index_lig][index_col])) != EOF) {
        index_col++;

        if (index_col == SIDE_LENGTH) {
            index_col = 0;
            index_lig++;
        }
    }

   fermer_fichier(&f);

   return 0;
}

/* Get the product maximal for diagonals going to up.
 * That means the product like N1 * N2 * N3 * N4 (so starting from N1 to N4),
 * with the positions of N[1-4] like these ones:
 *          N4
 *       N3
 *    N2
 * N1
 */
static unsigned long
get_max_product_diagonal_up(unsigned int nbers[SIDE_LENGTH][SIDE_LENGTH])
{
    unsigned long max = 0;

    for (int j = 0; j < COMMON_INDEX_MAX; j++) {
        for (int i = NBER_PRODUCT_COUNT - 1; i < SIDE_LENGTH; i++) {
            for (int k = 0; i - k >= NBER_PRODUCT_COUNT - 1 &&
                 j + k < COMMON_INDEX_MAX; k++)
            {
                unsigned long tmp = 1;

                for (int l = 0; l < NBER_PRODUCT_COUNT; l++) {
                    unsigned int n = nbers[i - k - l][j + k + l];

                    if (n == 0) {
                        k = k + 1;
                        break;
                    }
                    tmp = tmp * n;
                }
                if (tmp > max) {
                    max = tmp;
                }
            }
        }
    }
    return max;
}

/* Get the product maximal for diagonals going to down.
 * That means the product like N1 * N2 * N3 * N4 (so starting from N1 to N4),
 * with the positions of N[1-4] like these ones:
 * N1
 *    N2
 *      N3
 *         N4
 */
static unsigned long
get_max_product_diagonal_down(unsigned int nbers[SIDE_LENGTH][SIDE_LENGTH])
{
    unsigned long max = 0;
    /* This variable lets us not redo some calculations. Indeed, on the first
     * iteration of the first loop, we check all the diagonals going down from
     * the main one to the one the most on the right.
     * Once that done, we have to prevent j to become greater than i else the
     * diagonals on the right, already checked, will be redone. */
    int max_j = SIDE_LENGTH - NBER_PRODUCT_COUNT + 1;

    for (int i = 0; i < COMMON_INDEX_MAX; i++) {
        for (int j = 0; j < max_j; j++) {
            for (int k = 0; i + k < COMMON_INDEX_MAX &&
                 j + k < COMMON_INDEX_MAX; k++)
            {
                unsigned long tmp = 1;

                for (int l = 0; l < NBER_PRODUCT_COUNT; l++) {
                    unsigned int n = nbers[i + k + l][j + k + l];

                    if (n == 0) {
                        k = k + 1;
                        break;
                    }
                    tmp = tmp * n;
                }
                if (tmp > max) {
                    max = tmp;
                }
            }
        }
        max_j = i + 1;
    }
    return max;
}

/* Get the product maximal for numbers on a same column.
 * That means the product like N1 * N2 * N3 * N4 (so starting from N1 to N4),
 * with the positions of N[1-4] like these ones:
 * N1
 * N2
 * N3
 * N4
 */
static unsigned long
get_max_product_vertical(unsigned int nbers[SIDE_LENGTH][SIDE_LENGTH])
{
    unsigned long max = 1;

    for (int col = 0; col < SIDE_LENGTH; col++) {
        for (int lig = 0; lig < COMMON_INDEX_MAX; lig++) {
            unsigned long tmp = 1;

            for (int i = 0; i < NBER_PRODUCT_COUNT; i++) {
                unsigned int n = nbers[lig + i][col];

                if (n == 0) {
                    lig = lig + 1;
                    break;
                }
                tmp = tmp * n;

            }
            if (tmp > max) {
                max = tmp;
            }
        }
    }
    return max;
}

/* Get the product maximal for numbers on a same line.
 * That means the product like N1 * N2 * N3 * N4 (so starting from N1 to N4),
 * with the positions of N[1-4] like these ones:
 * N1 N2 N3 N4
 */
static unsigned long
get_max_product_horizontal(unsigned int nbers[SIDE_LENGTH][SIDE_LENGTH])
{
    unsigned long max = 1;

    for (int i = 0; i < SIDE_LENGTH; i++) {
        unsigned int *line;

        line = nbers[i];

        for (int j = 0; j < COMMON_INDEX_MAX; j++) {
            unsigned long tmp = 1;

            for (int k = 0; k < NBER_PRODUCT_COUNT; k++) {
                unsigned int n = line[j + k];

                if (n == 0) {
                    j = j + 1;
                    break;
                }
                tmp = tmp * n;
            }
            if (tmp > max) {
                max = tmp;
            }
        }
    }
    return max;
}

static unsigned long
get_max_product(unsigned int nbers[SIDE_LENGTH][SIDE_LENGTH])
{
    unsigned long max, tmp;

    max = get_max_product_horizontal(nbers);

    tmp = get_max_product_vertical(nbers);
    max = MAX(max, tmp);

    tmp = get_max_product_diagonal_down(nbers);
    max = MAX(max, tmp);

    tmp = get_max_product_diagonal_up(nbers);
    max = MAX(max, tmp);

    return max;
}

int main(void)
{
    unsigned int nbers[SIDE_LENGTH][SIDE_LENGTH];

    if (read_numbers(nbers) == 0) {
        printf("%ld\n", get_max_product(nbers));
    }

    return 0;
}
