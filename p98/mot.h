#ifndef _MOT_H_
#define _MOT_H_

#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "donnees.h"
#include "tab.h"
#include "visu.h"
#include "nbre.h"
#include <math.h>

unsigned long valMot(char* mot, unsigned int* tabVal);
unsigned int areAnagramSquare(dataHach *d);
bool egaliteMot(char* s1, char *s2);
void maxWords(FILE* f, unsigned int *maxLong, unsigned int* maxSumAscii);
unsigned int sumAsciiMot(char *mot);
unsigned int longeurMot(char *mot);
void analyseMot(char* mot, unsigned char* tab);
bool areAnagramesWords(unsigned char *tab1, unsigned char *tab2);

#endif
