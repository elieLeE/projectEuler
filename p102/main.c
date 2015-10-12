#include <stdio.h>
#include "structure.h"
#include "fichier.h"

int main(){
    int compt = 0, i = 0;
    triangle tabTri[NBRE_TRIANGLE];

    FILE *f = ouvFichier("p102_triangles.txt");

    lectureFichier(f, tabTri);

    for(i=0; i<NBRE_TRIANGLE; i++){
	if(canContainOrigin(tabTri[i])){
	    if(containOrigin(tabTri[i])){
		compt++;
	    }
	}
    }

    printf("compt : %d\n", compt);

    fermetureFichier(&f);

    return 0;
}
