#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * le nombre "objectif finit par 1 0 
 * => le nombre racine finit par un 0 
 * ==> le nombre objectif finit par 2 0s (le nombre de zero double quand on passe au carre
 * il finit par 900 => le nombre racine finit par 30 ou 70
 * */

#define DEBUT (long)sqrt((long)1121314151617181910)
#define FIN (long)sqrt((long)1929394959697989990)
#define NBRE_DIGITS 19

//le nombre au carre se finit par un 0 => le nombre normal doit lui-aussi se terminer par un 0

void digitsOfNbre(long n, char* tab)
{
    long n2 = n, n3 = n;
    int i = NBRE_DIGITS - 1;

    while (n2 >= 1) {
        n2 = n2 / 10;
        tab[i] = n3 - n2 * 10;
        i--;
        n3 = n3 / 10;
    }
}

bool nbreOK(long n)
{
    char tab[NBRE_DIGITS] = {0};
    int i = 0;

    digitsOfNbre(n, tab);

    for (i = 0; i < 9; i++) {
        if (tab[2 * i] != (i + 1)) {
            return false;
        }
    }
    if (tab[NBRE_DIGITS - 1] == 0) {
        return true;
    }
    return false;
}

int main()
{
    long i = DEBUT;
    bool b = true;

    i = floor(i) + 10;

    while (i < FIN) {
        if (nbreOK(i * i)) {
            break;
        }

        if (b) {
            i += 40;
            b = false;
        } else {
            i += 60;
            b = true;
        }
    }
    printf("%ld\n", i);

    return 0;
}
