#include "fichier.h"

FILE* ouvFichier(char *name){
    FILE* f = fopen(name, "r");
    if(f==NULL){
	fprintf(stderr, "erreur ouverture fichier, fichier %s, ligne %d\n", __FILE__, __LINE__);
	exit(0);
    }
    return f;
}

void lectureFichier(FILE* f, triangle tabTri[]){
    int i = 0, j = 0;
    for(i=0; i<NBRE_TRIANGLE; i++){
	for(j=0; j<3; j++){
	    fscanf(f, "%d%d", &tabTri[i].tab[j].x, &tabTri[i].tab[j].y);
	}
    }
}

void fermetureFichier(FILE** f){
    fclose(*f);
}

