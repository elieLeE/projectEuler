#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "graphe.h"

void allocTab2D(unsigned int*** matrice);
void allocGraphe(sommet ***g);

void liberationGraphe(sommet** g);
void liberationTab2D(unsigned int** matrice);

#endif
