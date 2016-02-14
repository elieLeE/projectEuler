#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "../shared/fichier.h"
#include "../shared/alloc.h"

int main(){
    unsigned int** matrice = (unsigned int**)allocTab2D(TAILLE_MATRICE, TAILLE_MATRICE, sizeof(unsigned int));

#if MODE
    FILE* fichier = ouvFichier("test.txt", "r");
#else 
    FILE* fichier = ouvFichier("p081_matrix.txt", "r");
#endif

    lireMatrice(fichier, matrice, TAILLE_MATRICE, TAILLE_MATRICE);
    printf("%d\n", shorterWay(matrice));

    liberationTab2D((void**)matrice, TAILLE_MATRICE);
    fermerFichier(&fichier);
    return 0;
}
