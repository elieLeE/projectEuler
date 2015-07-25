#ifndef _LISTE_ELEM_H_
#define _LISTE_ELEM_H_

#include "donnees.h"
#include "liste_elem_imp.h"
#include "liste_val_poss.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void liberationElem(liste_elem l);
void nouvElem(S_elem *e);
liste_elem creerListeElem();
void ajoutElemElem(liste_elem* l, S_elem e);
bool estVideElem(liste_elem l);

#endif
