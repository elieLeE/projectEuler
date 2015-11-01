#ifndef _TAB_H_
#define _TAB_H_

#include <stdio.h>
#include <stdlib.h>
#include "triplet.h"

void echange(int *a, int *b);
void copieTab(int *tab1, int *tab2, int ind);
void visuTab(int *tab);
long tabToNbre(int *tab);
void initTab(int *tab);

#endif
