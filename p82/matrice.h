#ifndef _MATRICE_H_
#define _MATRICE_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "alloc.h"

void affMatrice(unsigned int** matrice);
int shorterWay(unsigned int**matrice);
unsigned int minAB(unsigned int a, unsigned int b);
void searchDescente(unsigned int** tabDescente, unsigned int** matrice, int col);
void searchMonte(unsigned int** tabMonte, unsigned int** matrice, int col);

#endif
