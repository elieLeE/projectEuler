#ifndef _TABHACH_H_
#define _TABHACH_H_

#include <stdio.h>
#include <stdlib.h>
#include "../shared/liste.h"
#include "fichier.h"
#include "donnees.h"
#include "mot.h"
#include "visu.h"
#include "../shared/liste.h"

unsigned int maxSquare(liste*** tabH, unsigned int tL, unsigned int tC);
void liberationTabHach(liste*** tabH, unsigned int tL, unsigned int tC);
void remplissageTabHach(FILE *f, liste*** tabhach);
liste* searchListe(liste* l, char* mot);

#endif
