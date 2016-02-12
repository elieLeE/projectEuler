#ifndef _MATRICE_H_
#define _MATRICE_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "alloc.h"
#include <stdbool.h>

typedef struct pos pos;
struct pos{
    int lig, col;
};

unsigned int pccAToB(unsigned int** matrice, bool tabB[][TAILLE_MATRICE], pos *dep, pos *obj);
unsigned int pccToB(unsigned int** matrice, pos *obj);
void affMatrice(unsigned int** matrice);
unsigned int shorterWay(unsigned int**matrice);
unsigned int minAB(unsigned int a, unsigned int b);

#endif
