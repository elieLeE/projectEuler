#ifndef _GRILLE_H_
#define _GRILLE_H_

#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "liste.h"
#include <time.h>

char nbreDoublonLigne(char ligne[NBRE_COL]);
char nbreDoublonCol(char grille[NBRE_LIGNE][NBRE_COL], char num_col);
void visuInit(char grille[NBRE_LIGNE][NBRE_COL]);
void initBlocs(S_liste blocs[NBRE_BLOC]);

#endif
