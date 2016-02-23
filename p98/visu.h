#ifndef _VISU_H_
#define _VISU_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "../shared/liste.h"
#include "mot.h"

void visuOK(liste*** l, unsigned int tL, unsigned int tC);
void visuTabHach(liste*** tabH, unsigned int tL, unsigned int tC);
void visuCouple(void* data);
void visuWord(void *data);

#endif

