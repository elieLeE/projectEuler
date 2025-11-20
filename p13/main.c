#include <limits.h>

#include "../libC/src/io/io.h"
#include "../libC/src/mem/mem.h"

#define NBER_OF_NBERS 100
#define NBER_OF_PART 5
#define SIZE_PART 10

int read_numbers(unsigned long nbers[NBER_OF_NBERS][NBER_OF_PART])
{
    FILE *f = ouv_fichier("numbers.txt", "r");
    char c;
    unsigned int number_counter = 0, digit_counter = 0, part_counter = 0;
    unsigned long tmp = 0;

    if (f == NULL) {
        return -1;
    }

    while ((c = getc(f)) != EOF) {
        if (c < 48 || c > 57) {
            continue;
        }
        tmp += (c - '0');

        digit_counter++;
        if (digit_counter == SIZE_PART) {
            nbers[number_counter][part_counter] = tmp;
            part_counter++;

            if (part_counter == NBER_OF_PART) {
                number_counter++;

                digit_counter = 0;
                part_counter = 0;

                if (number_counter > NBER_OF_NBERS) {
                    break;
                }
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

unsigned long
get_sum_part_numbers(unsigned long nbers[NBER_OF_NBERS][NBER_OF_PART],
                     int idx_part)
{
    unsigned long sum = 0;

    for (int i = 0; i < NBER_OF_NBERS; i++) {
        sum += nbers[i][idx_part];
    }

    return sum;
}

void get_sum(unsigned long nbers[NBER_OF_NBERS][NBER_OF_PART],
             unsigned long out[NBER_OF_PART])
{
    unsigned long tmp;
    int carry = 0;

     for (int i = NBER_OF_PART - 1; i >= 0; i--) {
        tmp = get_sum_part_numbers(nbers, i) + carry;
        carry = tmp / 10000000000;

        out[0] = tmp;
     }
}

int main(void)
{
     unsigned long nbers[NBER_OF_NBERS][NBER_OF_PART];
     unsigned long sum[NBER_OF_PART];
     unsigned long answer;

     for (int i = 0; i < NBER_OF_NBERS; i++) {
         p_clear(nbers[i], NBER_OF_PART);
     }

     if (read_numbers(nbers) != 0) {
        printf ("error when reading numbers\n");
        return -1;
     }

     get_sum(nbers, sum);
     answer = sum[0];
     while (answer > 10000000000) {
         answer = answer / 10;
     }
     printf("%ld\n", answer);

     return 0;
}
