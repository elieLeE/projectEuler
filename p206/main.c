#include "nbre.h"
#include "math.h"
#include <stdbool.h>

/**
 * le nombre "objectif finit par 1 0 
 * => le nombre racine finit par un 0 
 * ==> le nombre objectif finit par 2 0s (le nombre de zero double quand on passe au carre
 * il finit par 900 => le nombre racine finit par 30 ou 70
 * */

#define DEBUT (long)sqrt((long)1121314151617181910)
#define FIN (long)sqrt((long)1929394959697989990)

//le nombre au carre se finit par un 0 => le nombre normal doit lui-aussi se terminer par un 0

int main(){
    long i = DEBUT;
    i = floor(i)+10;
    printf("i : %ld\n", i);
    bool b = true;

    while(i<FIN){
	if(nbreOK(i*i)){
	    break;
	}
	if(b){
	    i+=40;
	    b = false;
	}
	else{
	    i+=60;
	    b = true;
	}
    }
    printf("nbre : %ld => i*i : %ld\n", i, i*i);

    return 0;
}
