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

void lectureGrille(FILE* fichier, char grille[NBRE_LIGNE][NBRE_COL]){ 
    char ligne[20];
    char c = 0;
    char i = 0, j = 0;
    bool go = true;
    fgets(ligne, 20, fichier);
    for(i=0; i<NBRE_LIGNE; i++){
	j = 0;
	while((grille[i][j] = (char)(fgetc(fichier) - 48)) != (char)-38 && grille[i][j] != (char)-49){
	    j++;
	}
    }
}


