#include "fichier.h"

void lectureFichier(FILE* f, triangle tabTri[]){
    int i = 0, j = 0;
    for(i=0; i<NBRE_TRIANGLE; i++){
	for(j=0; j<3; j++){
	    fscanf(f, "%d%d", &tabTri[i].tab[j].x, &tabTri[i].tab[j].y);
	}
    }
}
