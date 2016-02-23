#include "nbre.h"

void firstCarre(unsigned int nbreDigit, unsigned long* firstC, unsigned long *lastC){
    unsigned long n = 1, n2 = 9;
    unsigned int i;

    for(i=0; i<nbreDigit; i++){
	n = n*10+1;
	n2 = n2*10+9;
    }
    *firstC = (unsigned int)(sqrt(n)+1);;
    *lastC = (unsigned int)(sqrt(n2));
}
