#ifndef _ALGO1_H_
#define _ALGO1_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

/*char searchFirstListeNonVide(liste_elem *tab_hach, liste_elem *first_elem);
void searchLastElem(liste_elem l, liste_elem *last_elem);
void liaisonTabHach(liste_elem *tab_hach, liste_elem*);
bool nextRemplissage(S_elem *e);
bool valPrise(liste_elem_imp l, char val);
void resolutionSudoku(liste_elem file_prio);
liste_elem initTableHachage(char **grille);
void liberationFilePrio(liste_elem *l);*/

void resolutionSudoku(S_tab tabRes[8]);

void initTabRes(S_tab tab[8]);
void initSTab(S_tab t);
void initElem(S_elem *e);

void allocTabRes(S_tab tabRes[8]);
void allocElems(S_elem* e);
void allocElem(S_elem *e);

#endif

