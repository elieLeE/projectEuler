#ifndef _ALLOC2_H_
#define _ALLOC2_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "graphe.h"
#include "../shared/alloc.h"

//void allocTab2D(unsigned int*** matrice);
void allocGraphe(sommet ***g);

void liberationGraphe(sommet** g);
//void liberationTab2D(unsigned int** matrice);

#endif
