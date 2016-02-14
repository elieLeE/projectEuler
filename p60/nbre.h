#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdio.h>
#include <stdbool.h>
#include "donnees.h"
#include "../shared/nbre.h"

char nbreDigit(short nbre);
bool isPerm(element e1, element e2);
bool isPermTab(element e, element tab[], char nbreEval);

#endif
