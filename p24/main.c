#include <stdbool.h>
#include <stdio.h>

#define NBRE_OF_DIGIT 10
#define PERM_IDX 1000000

static void visu_tab(unsigned char *tab)
{
    int i = 0;

    for (i = 0; i < NBRE_OF_DIGIT; i++) {
        printf("%d", tab[i]);
    }
    printf("\n");
}

int search_perm_rec(unsigned char digits_nbre[NBRE_OF_DIGIT],
                    bool digits_done[NBRE_OF_DIGIT], unsigned int *count,
                    unsigned int depth)
{
    if (depth == NBRE_OF_DIGIT) {
        (*count)++;

        if ((*count) == PERM_IDX) {
            return 0;
        }
        return -1;
    }

    for (unsigned int i = 0; i < NBRE_OF_DIGIT; i++) {
        if (digits_done[i]) {
            continue;
        }

        digits_nbre[depth] = i;
        digits_done[i] = true;

        if (search_perm_rec(digits_nbre, digits_done,
                            count, depth + 1) == 0)
        {
            return 0;
        }
        digits_done[i] = false;
    }

    return -1;
}

int main()
{
    unsigned char digits_nbre[NBRE_OF_DIGIT] = {0};
    bool digits_done[NBRE_OF_DIGIT] = {false};
    unsigned int count = 0;

    if (search_perm_rec(digits_nbre, digits_done, &count, 0) == 0) {
        visu_tab(digits_nbre);
    } else {
        printf("permutation not foind\n");
    }

    return 0;
}
