#include <stdio.h>
#include <stdlib.h>
#include "../fichier.h"
#include "../defines.h"
#include "liste.h"
#include "test.h"

#define DEBUG 0

int main(){
    //la grille est composé de 9 blocs => grille[0] correspond au premier bloc, pas a la premiere ligne de la grille
    char grille[NBRE_BLOC][TAILLE_BLOC];
    S_liste blocs[NBRE_BLOC];
    char bloc_a_remplir = 0, c = 0;
    FILE* fichier = ouvFichier("p096_sudoku.txt", "r");

    srand(time(0));
    initBlocs(blocs);
    lectureGrille(fichier, grille, blocs);
    premierRemplissageBlocs(blocs);
    while((bloc_a_remplir = numBlocMaxDoublon(grille)) != -1){
	/*printf("grille : \n");
	visuGrille(grille);
	testNbreDoublonParBloc(grille);
	printf("bloc a remplir : %d\n", bloc_a_remplir);*/
	remplissageAleatoireBloc(blocs[bloc_a_remplir]);
	//scanf("%c", &c);
    }
    printf("\ngrille resolue !!\n");		
    
    visuGrille(grille);

#if DEBUG
    testEcritureBloc(grille, blocs);
    testDoublon(grille);
    testNbreDoublonParBloc(grille);
    testMaxDoublonBloc(grille);
    testRemplissageAleatoireBloc(blocs);
#endif

    fermerFichier(fichier);
    return 0;
}
