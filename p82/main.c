#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"
#include "matrice.h"
#include "../shared/fichier.h"

int main(){
    unsigned int** matrice;

    allocTab2D(&matrice);
#if MODE
    FILE* fichier = ouvFichier("test.txt", "r");
#else 
    FILE* fichier = ouvFichier("p082_matrix.txt", "r");
#endif

    lireMatrice(fichier, matrice, TAILLE_MATRICE, TAILLE_MATRICE);
    printf("%d\n", shorterWay(matrice));

    liberation(matrice);
    fermerFichier(&fichier);
    return 0;
}
