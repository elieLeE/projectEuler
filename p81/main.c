#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "alloc.h"
#include "matrice.h"

int main(){
    unsigned int** matrice;

    allocTab2D(&matrice);
#if MODE
    FILE* fichier = ouvFichier("test.txt");
#else 
    FILE* fichier = ouvFichier("p081_matrix.txt");
#endif

    lireMatrice(fichier, matrice);
    printf("%d\n", shorterWay(matrice));

    fermerFichier(&fichier);
    return 0;
}
