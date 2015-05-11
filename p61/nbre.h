#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "type_donnees.h"

bool nextNbre(bool tab[5], char *ind, l_tabhach tabHach[5][100], char n);
bool dernierNbre(l_tabhach tabHach[5][100], char left, char right, bool tab[5], char*);

#endif
