#include <stdio.h>
#include <stdbool.h>
#include "limits.h"

#define NBRE_RING 10
#define MAX_DIGIT NBRE_RING + 1
#define NBRE_TRIPLETS 5

/* A triplet has 3 rings. Each ring has an integer in it. */
typedef struct triplet_t {
    int values[3];
} triplet_t;

void init_triplets(triplet_t triplets[NBRE_TRIPLETS], int digits[MAX_DIGIT])
{
    triplet_t *t;

    for (int i = 0, j = NBRE_TRIPLETS; i < NBRE_TRIPLETS - 1; i++, j++) {
        t = &(triplets[i]);

        t->values[0] = digits[i];
        t->values[1] = digits[j];
        t->values[2] = digits[j+1];
    }
    t = &(triplets[NBRE_TRIPLETS - 1]);

    t->values[0] = digits[NBRE_TRIPLETS - 1];
    t->values[1] = digits[NBRE_RING - 1];
    t->values[2] = digits[NBRE_TRIPLETS];
}

int get_triplet_sum(triplet_t *t)
{
    return (t->values[0]) + (t->values[1]) + (t->values[2]);
}

bool is_possible_solution(triplet_t triplets[NBRE_TRIPLETS])
{
    int sum;

    for (int i = 0; i < NBRE_TRIPLETS; i++) {
        int *values = (triplets[i].values);

        /* If 10 is present is several triplets (so at pos 2 or 3 of triplets,
         * it will be impossible to have same sum for the triplets */
        if (((values[1]) == 10) || ((values[2]) == 10)) {
            return false;
        }
    }

    /* all triplets have to have the same sum */
    sum = get_triplet_sum(&triplets[0]);
    for (int i = 1; i < NBRE_TRIPLETS; i++) {
        if (sum != get_triplet_sum(&triplets[i])) {
            return false;
        }
    }
    return true;
}

/* looking for the triplet that has the minimal value for its external node */
int get_lowest_external_node_triplet_idx(triplet_t triplets[NBRE_TRIPLETS])
{
    int min, ind;

    min = (triplets[0].values[0]);
    ind = 0;

    for (int i = 1; i < NBRE_TRIPLETS; i++) {
        triplet_t *t = &(triplets[i]);

        if (min > (t->values[0])) {
            min = (t->values[0]);
            ind = i;
        }
    }
    return ind;
}

int get_nber_from_triplet(triplet_t *t)
{
    return (t->values[0]) * 100 + (t->values[1]) * 10 + (t->values[2]);
}

unsigned long get_nber_from_triplets(triplet_t *t)
{
    int current_idx, idx_start;
    unsigned long n;

    idx_start = get_lowest_external_node_triplet_idx(t);
    n = get_nber_from_triplet(&t[idx_start]);

    current_idx = (idx_start + 1) % NBRE_TRIPLETS;
    do {
        /* 10 value be only on the ring 1 of one of the triplet
         * (cf is_possible_solution) */
        if ((t[current_idx].values[0]) == 10) {
            n *= 10000;
        } else {
            n *= 1000;
        }
        n += get_nber_from_triplet(&t[current_idx]);

        current_idx = (current_idx + 1) % NBRE_TRIPLETS;
    } while (current_idx != idx_start);

    return n;
}

unsigned long search_best_triplet_rec(int digits[MAX_DIGIT],
                                      bool digits_done[NBRE_RING],
                                      int depth)
{
    unsigned long max_n = 0;

    if (depth == NBRE_RING) {
        /* 0 is skipped. There is no 0 in the array digits.
         * So, the digits from 1 to 'last_digit' are on 'last_digit - 1' sits.
         */
        triplet_t triplets[NBRE_TRIPLETS];

        init_triplets(triplets, digits);

        if (is_possible_solution(triplets)) {
            return get_nber_from_triplets(triplets);
        }
        return 0;
    }

    for (int i = 1; i <= MAX_DIGIT; i++) {
        unsigned long tmp;

        if (digits_done[i]) {
            continue;
        }

        digits[depth] = i;
        digits_done[i] = true;

        tmp = search_best_triplet_rec(digits, digits_done, depth + 1);
        if (tmp > max_n) {
            max_n = tmp;
        }
        digits_done[i] = false;
    }

    return max_n;
}

int main()
{
    int digits[MAX_DIGIT] = {0};
    bool digits_done[MAX_DIGIT] = {false};

    printf("%ld\n", search_best_triplet_rec(digits, digits_done, 0));

    return 0;
}

