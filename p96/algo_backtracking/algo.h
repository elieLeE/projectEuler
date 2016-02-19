#ifndef _ALGO1_H_
#define _ALGO1_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "liste_elem.h"

char searchFirstListeNonVide(liste_elem tab_hach[NBRE_VAL_POSS], liste_elem *first_elem);
void searchLastElem(liste_elem l, liste_elem *last_elem);
void liaisonTabHach(liste_elem tab_hach[NBRE_VAL_POSS], liste_elem*);
bool nextRemplissage(S_elem *e);
bool valPrise(liste_elem_imp l, char val);
void resolutionSudoku(liste_elem file_prio);
liste_elem initTableHachage(char grille[NBRE_LIGNE][NBRE_COL], liste_elem elem[NBRE_VAL_POSS]);
void liberationFilePrio(liste_elem *l);

#endif

