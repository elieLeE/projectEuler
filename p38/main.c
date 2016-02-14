#include <stdio.h>
#include "nbre.h"
#include "tab.h"

int main(void)
{
    int i = 10000;

    while(true){
        if(becomePandigital(i)){
            break;
        }
        i--;
    }

    printf("%ld\n", nbreToPandigital(i));

    return 0;
}

