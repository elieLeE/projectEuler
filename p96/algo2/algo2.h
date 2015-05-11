#ifndef _ALGO2_h_
#define _ALGO2_H_

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "liste.h"
#include <time.h>
#include "grille.h"

char numBlocMaxDoublon(char grille[NBRE_LIGNE][NBRE_COL]);
char nbreDoublonLigne(char ligne[NBRE_COL]);
char nbreDoublonCol(char grille[NBRE_LIGNE][NBRE_COL], char num_col);
void premierRemplissageBlocs(S_liste blocs[NBRE_BLOC]);
void remplissageAleatoireBloc(S_liste bloc);

#endif
