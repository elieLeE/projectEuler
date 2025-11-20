#include <stdio.h>
#include "structure.h"
#include "fichier.h"
#include "../shared/fichier.h"

int main(){
    int compt = 0, i = 0;
    triangle tabTri[NBRE_TRIANGLE];

    FILE *f = ouvFichier("p102_triangles.txt", "r");

    lectureFichier(f, tabTri);

    for(i=0; i<NBRE_TRIANGLE; i++){
	if(canContainOrigin(tabTri[i])){
	    if(containOrigin(tabTri[i])){
		compt++;
	    }
	}
    }

    printf("%d\n", compt);

    fermerFichier(&f);

    return 0;
}
