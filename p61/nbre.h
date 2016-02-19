#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "type_donnees.h"
#include "tabhach.h"

bool nextNbre(bool tab[5], int *ind, l_tabhach tabHach[5][100], unsigned char n);
bool dernierNbre(l_tabhach tabHach[5][100], unsigned char left, unsigned char right, bool tab[5], int*);

#endif
