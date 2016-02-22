#ifndef _P77_NBRE_H_
#define _P77_NBRE_H_

#include <stdio.h>
#include <stdlib.h>
#include "../shared/nbre.h"
#include "../shared/tab.h"

#define LIMITE 5000
#define TAILLE_TAB_PRIME 1000

void visuElem(void* elem); 
void remplissageTabPrime(unsigned int *tabPrime);
unsigned int nbreAdd(unsigned int n, unsigned int m, unsigned int* tabPrime);

#endif
