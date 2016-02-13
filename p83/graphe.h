#ifndef _GRAPHE_H_
#define _GRAPHE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alloc.h"
#include "donnees.h"
#include "sommet.h"
#include "matrice.h"

void remplissageGraphe(sommet** g, unsigned int** matrice);
unsigned int shorterWay(unsigned int** matrice);
void affSommetAdded(sommet** g);

#endif

