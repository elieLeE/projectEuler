#ifndef _SET_H_
#define _SET_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../shared/alloc.h"

#define TAILLE_TAB 3025

#define DEBUG 0

unsigned int longestSet(unsigned int *tab);
void calculSet(unsigned int *tab, double val, bool *tabVal, bool *tabB, unsigned int numStep);

#endif
