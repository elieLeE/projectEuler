#ifndef _GRAPHE_H_
#define _GRAPHE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alloc.h"
#include "donnees.h"

void initSommet(sommet** s, unsigned int** matrice, pos p);
void remplissageGraphe(sommet** g, unsigned int** matrice);
unsigned int shorterWay(unsigned int** matrice);

#endif

