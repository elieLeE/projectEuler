#ifndef _GRILLE_H_
#define _GRILLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "donnees.h"
#include <time.h>

void liberationGrille(char ***grille);
void allocGrille(char ***grille);
void reInitTab(char tab[10], char taille);
bool verificationReponse(char **grille);
bool verifLigne(char **grille);
bool verifCol(char **grille);
bool verifBlocs(char **grille);
void visuGrille(char grille[NBRE_LIGNE][NBRE_COL]);
/*void searchElemImpLigne(char *grille, bool *tab, liste_elem_imp *l_elem_imp, char col);
void searchElemImpCol(char **grille, bool *tab, liste_elem_imp *l_elem_imp, char ligne, char col);
void searchElemImpBloc(char **grille, bool *tab, liste_elem_imp *l_elem_imp, char ligne, char col);
int nbreDeValPoss(char **grille, S_elem *e, char ligne, char col);*/
   
#endif
