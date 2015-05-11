#ifndef _LISTE_VAL_POSS_H_
#define _LISTE_VAL_POSS_H_

#include "donnees.h"
#include "liste_val_poss.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void liberationValPoss(liste_val_poss *l);
liste_val_poss creerListeValPoss();
void ajoutElemValPoss(liste_val_poss* l, char val);
bool estVideValPoss(liste_val_poss l);
void visuListeValPoss(liste_val_poss l);

#endif
