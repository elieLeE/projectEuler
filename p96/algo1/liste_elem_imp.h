#ifndef _LISTE_ELEM_IMP_H_
#define _LISTE_ELEM_IMP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "donnees.h"


void liberationElemImp(liste_elem_imp *l);
liste_elem_imp creerListeElemImp();
bool estVideElemImp(liste_elem_imp l);
void ajoutElemElemImp(liste_elem_imp *l, char *val, S_pos pos);
void visuListeVal(liste_elem_imp l);
void visuListeElemImp(liste_elem_imp l);

#endif

