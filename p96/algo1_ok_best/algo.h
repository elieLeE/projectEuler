#ifndef _ALGO1_H_
#define _ALGO1_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "liste_elem.h"

char searchFirstListeNonVide(liste_elem *tab_hach, liste_elem *first_elem);
void searchLastElem(liste_elem l, liste_elem *last_elem);
void liaisonTabHach(liste_elem *tab_hach, liste_elem*);
bool nextRemplissage(S_elem *e);
bool valPrise(liste_elem_imp l, char val);
void resolutionSudoku(liste_elem file_prio);
liste_elem initTableHachage(char **grille);
void liberationFilePrio(liste_elem *l);

#endif

