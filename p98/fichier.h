#ifndef _FICHIER_H_
#define _FICHIER_H_

#include <stdio.h>
#include <stdlib.h>
#include "../shared/liste.h"
#include "../shared/alloc.h"
#include "../shared/nbre.h"

void maxWords(FILE* f, unsigned int* maxLong, unsigned int* maxSumAscii);
void lecture(FILE *f, liste** tabHach);

#endif
