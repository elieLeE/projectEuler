#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"
#include "liste_elem.h"
#include "liste_elem_imp.h"
#include "liste_val_poss.h"
#include "grille.h"
#include "algo.h"
#include "fichier.h"

#define NBRE_GRILLE 50

int main(){
    FILE* fichier = NULL;
    char grille[NBRE_LIGNE][NBRE_COL];
    liste_elem tab_hach[9];
    liste_elem file_prio;
    int sum = 0, i = 0;

    fichier = ouvFichier("p096_sudoku.txt", "r+");
    for(i=0; i<NBRE_GRILLE; i++){
	printf("grille %d\n", i);
	lectureGrille(fichier, grille);
	file_prio = initTableHachage(grille, tab_hach);
	resolutionSudoku(file_prio);
	sum = sum + grille[0][0]*100 + grille[0][1]*10+grille[0][2];
	liberationFilePrio(&file_prio);
    }

    printf("result : %d\n", sum);
    fermerFichier(fichier);
    return 0;
}
