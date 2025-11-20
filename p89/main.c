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

    while(nextLigne(fichier, ligne)){
	if(ligne[strlen(ligne)-1] == '\n'){
	    ligne[strlen(ligne)-1] = '\0';
	}
	tmp = nbreCarSaved(ligne);
	compt += tmp;
    }

    printf("%d\n", compt);

    fermerFichier(fichier);
    return 0;
}
