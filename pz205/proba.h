#ifndef _PROBA_H_
#define _PROBA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "tab.h"

#define NBRE_DES_4 9
#define NBRE_DES_6 6
#if NBRE_DES_4*4 > NBRE_DES_6*6
#define TAILLE_TAB NBRE_DES_4*4 + 1
#else
#define TAILLE_TAB NBRE_DES_6*6 + 1
#endif

#define NBRE_POSS_9_DES (double)(pow(4, NBRE_DES_4))
#define NBRE_POSS_6_DES (double)(pow(6, NBRE_DES_6))

void initDes(int des[], int nbredes);
bool nextConfig(int tab[], int nbreDes, int);
double sumProba(int tab1[], int tab2[]);

#endif
