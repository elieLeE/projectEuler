#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../libC/src/math/nbre.h"

/* this method produces the next configuration of the dice from the previous
 * one.
 * for example, the first configuration is: 012345 (as to say the numbers O, 1,
 * 2, 3, 4 and 5 on the side of the dice).
 * From this configuration, the next one will be 012346, then 012347.
 * Once the last number will have reached to 9 (so the configuration 012349),
 * the next configuration will 012356 (and no 012359) !
 */
static int get_next_dice_config(bool dice[10])
{
    int side_num, count;

    /* looking for a side that can have a bigger number */
    side_num = 9;
    while (dice[side_num] && side_num >= 0) {
        side_num--;
    }

    /* all numbers from 4 to 9 are in the dice (6 numbers). The actual
     * configuration (so the one before entering in this method) was the last
     * one */
    if (side_num <= 3) {
        return -1;
    }

    /* So, we have skipped all the side that can not be increased (tab was true
     * from 9 to side_num ° 1). Now, we are looking for the first case with
     * the value false. It will be correspond to the number that can be
     * increased */
    while(!dice[side_num] && side_num >=  0) {
        side_num--;
    }

    /* We increase it */
    dice[side_num] = false;
    dice[side_num + 1] = true;

    /* Now, we have to reset all the side with a bigger number that the one
     * just increased. If this is not done, then from the configuration 012349,
     * we will have the configuration 012359. So, ma ny configurations, like
     * 012346 will be skipped */
    /* First, we have to count the side that are good, as to say, the side with
     * a smaller number that the one just increased. It is not necessary to
     * reset these ones. */
    count = 0;
    for (int i = 0; i < side_num; i++) {
        if (dice[i]) {
            count++;
        }
    }
    /* we know that dice[side_num + 1] = true */
    count++;

    /* Then, starting from 'side_num + 2' (the number previous increased is on
     * 'side_num + 1', we set all the case to true until count reaches 6. Once
     * that done, we know that all side have been set and all the reset of the
     * array has to be set to false */
    for (int i = side_num + 2; i < 10; i++) {
        if (count < 6) {
            dice[i] = true;
            count++;
        } else {
            dice[i] = false;
        }
    }
    return 0;
}

/* just build of the squares to verify by the dices */
static void build_squares(int squares[10][2])
{
    for (int i = 1; i < 10; i++) {
        unsigned char digits[2];
        unsigned int digits_nber;

        digits_nber = get_digits_from_number(i * i, digits);
        if (digits_nber > 2) {
            fprintf(stderr, "We got %d digits for the square of %d (%d)\n",
                    digits_nber, i, i * i);
        }
        squares[i][0] = digits[0];

        if (digits_nber == 1) {
            squares[i][1] = 0;
        } else {
            squares[i][1] = digits[1];
        }
    }
}

/* As 6 and 9 can be used with each other (6 is 9 and 9 is 6), when a dice has
 * a 6, it also has a 9.
 * So, I see two ways to do that:
 * - a copy of the tab, set the value of the case 6 and 9 to true if one of
 *   them is true, test if the squares can be done and do the opposite copy of
 *   the first step.
 * - save the values of the case 6 and 9. Set the two of them to true if one
 *   of them is true, do the tests and then reset the values.
 * I choose the second solution. It is just better according to me. */
void save_dice_values(const bool dice[10], bool dice_values_saving[2])
{
    dice_values_saving[0] = dice[6];
    dice_values_saving[1] = dice[9];
}

void reset_dice_values(const bool dice_values_saving[2], bool dice[10])
{
    dice[6] = dice_values_saving[0];
    dice[9] = dice_values_saving[1];
}

void get_dice_extended(bool dice[10])
{
    dice[6] = dice[9] = dice[6] || dice[9];
}

/* Test if the dices can do all the squares */
static bool
can_dices_do_all_squares(const bool dices[2][10], const int squares[10][2])
{
    const bool *first_dice = dices[0];
    const bool *second_dice = dices[1];

    for (int i = 1; i < 10; i++) {
        int idx1 = squares[i][0], idx2 = squares[i][1];

        /* The dices can be exchange. So, for a square, a dice can do the first
         * digit and the second dice the second digit. And then, for another
         * square, the dices can be swapped and so the second dice do the first
         * digit and the first dice do the first digit */
        if ((!first_dice[idx1] || !second_dice[idx2]) &&
            (!first_dice[idx2] || !second_dice[idx1]))
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    bool dices[2][10] = {{true, true, true, true, true, true}, {}};
    int squares[10][2];
    bool dices_values_saving[2][2];
    unsigned int count = 0;

    build_squares(squares);

    do {
        memcpy(dices[1], dices[0], sizeof(bool) * 10);

        save_dice_values(dices[0], dices_values_saving[0]);
        get_dice_extended(dices[0]);

        while (get_next_dice_config(dices[1]) == 0) {
            save_dice_values(dices[1], dices_values_saving[1]);
            get_dice_extended(dices[1]);

            if (can_dices_do_all_squares(dices, squares)) {
                count++;
            }
            reset_dice_values(dices_values_saving[1], dices[1]);
        }

        reset_dice_values(dices_values_saving[0], dices[0]);
    } while (get_next_dice_config(dices[0]) == 0);

    printf("%d\n", count);

    return 0;
}
