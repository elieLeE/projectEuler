#include "fichier.h"

void maxWords(FILE* f, unsigned int *maxLong, unsigned int* maxSumAscii){
    char *s = my_calloc(50*sizeof(char));
    unsigned int longMot = 0, sumMot = 0, i;
    *maxLong = 0;
    *maxSumAscii = 0;
    while(feof(f)==0){
	fgets(s, 50, f);
	longMot = strlen(s)-1;
	sumMot = 0;
	s[longMot] = '\0';
	for(i=0; i<longMot; i++){
	    sumMot = sumMot + s[i];
	}
	*maxLong = max(*maxLong, longMot);
	*maxSumAscii = max(*maxSumAscii, sumMot);
    }
}
