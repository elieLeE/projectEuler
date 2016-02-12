#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "alloc.h"
#include "matrice.h"

int main(){
    unsigned int** matrice;

    allocTab2D(&matrice);
    FILE* fichier = ouvFichier("p081_matrix.txt");

    lireMatrice(fichier, matrice);
    //affMatrice(matrice);

    fermerFichier(&fichier);
    return 0;
}
