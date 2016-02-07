#include "fichier.h"

FILE* ouvFichier(char *name, char *mode){
    FILE* fichier = fopen(name, mode);
    if(fichier == NULL){
	printf("impossible d'ouvrir %s\n", name);
	exit(1);
    }
    return fichier;
}

void fermerFichier(FILE* fichier){
    if(fichier == NULL){
	printf("pointeur null !!\n");
    }
    fclose(fichier);
}

bool nextLigne(FILE* fichier, char ligne[MAX]){ 
    return !(fgets(ligne, MAX, fichier) == NULL);
}


