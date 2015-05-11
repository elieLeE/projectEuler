#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "liste.h"
#include "../grille.h"

void testListe();
void testEcritureBloc(char grille[NBRE_LIGNE][NBRE_COL], S_liste bloc[NBRE_BLOC]);
void testMaxDoublonBloc(char grille[NBRE_LIGNE][NBRE_COL]);

#endif
