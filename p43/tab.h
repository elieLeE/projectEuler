#ifndef _TAB_H_
#define _TAB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../shared/swap.h"

void echange(unsigned int *a, unsigned int *b);
void copieTab(unsigned int *tab1, unsigned int *tab2, unsigned int ind);
void visuTab(unsigned int *tab);
long tabToNbre(unsigned int *tab);

#endif
