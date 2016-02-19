#ifndef _GRILLE_H_
#define _GRILLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "donnees.h"
#include "liste_elem.h"
#include <time.h>

void reInitTab(char tab[10], char taille);
bool verificationReponse(char grille[NBRE_LIGNE][NBRE_COL]);
bool verifLigne(char grille[NBRE_LIGNE][NBRE_COL]);
bool verifCol(char grille[NBRE_LIGNE][NBRE_COL]);
bool verifBlocs(char grille[NBRE_LIGNE][NBRE_COL]);
void visuGrille(char grille[NBRE_LIGNE][NBRE_COL]);
void searchElemImpLigne(char grille[NBRE_COL], bool tab[10], liste_elem_imp *l_elem_imp, char lig, char col);
void searchElemImpCol(char grille[NBRE_LIGNE][NBRE_COL], bool tab[10], liste_elem_imp *l_elem_imp, char ligne, char col);
void searchElemImpBloc(char grille[NBRE_LIGNE][NBRE_COL], bool tab[10], liste_elem_imp *l_elem_imp, char ligne, char col);
int nbreDeValPoss(char grille[NBRE_LIGNE][NBRE_COL], S_elem *e, char ligne, char col);
   
#endif
