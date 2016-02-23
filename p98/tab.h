#ifndef _TAB_H_
#define _TAB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "donnees.h"
#include "mot.h"

void visuTab(unsigned int* tab, char*);
void visuTab2(unsigned int* tab);
char** affectationMot(dataHach *d);
void setTab(unsigned int*tab, char* mot, unsigned long n);
bool nextCombi(unsigned int *tab, char *);
bool verifTab(unsigned int *tab, char*);
void initTab(unsigned int *tab);

#endif
