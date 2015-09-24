#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "verif_RN.h"

#define NBRE_GRILLE 50

int main(){
    unsigned int compt = 0, tmp;
    FILE* fichier = NULL;
    char ligne[20];
    fichier = ouvFichier("p089_roman.txt", "r");

    strcpy(ligne, "MMMDLXVIIII");
    tmp = nbreCarSaved(ligne);
    printf("ligne : %s => saved : %d\n", ligne, tmp);

    //return 0;

    while(nextLigne(fichier, ligne)){
	ligne[strlen(ligne)-1] = '\0';
	tmp = nbreCarSaved(ligne);
	compt += tmp;
	printf("%s => saved : %d, compt : %d\n", ligne, tmp, compt);
	/*if(isMinimal(ligne)){
	    ligne[strlen(ligne)-1] = '\0';
	    compt++;
	    printf("%s minimal\n", ligne);
	}
	else{
	    ligne[strlen(ligne)-1] = '\0';
	    printf("%s NON minimal\n", ligne);
	}*/
	//break;
    }

    printf("compt : %d\n", compt);

    fermerFichier(fichier);
    return 0;
}
