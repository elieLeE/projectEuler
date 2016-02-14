#ifndef _LISTE_H_
#define _LISTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "nbre.h"
#include "donnees.h"
#include "../shared/alloc.h"

void visuListe(cell l);
void ajoutCell(cell *l, short nbre);
liste creerListe();
void remplissageListe(cell *l);

#endif
