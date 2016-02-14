#include "fichier.h"

void nbreMaxCo(FILE* f, int* nbreMax, int *nbreTot){
    int i = 0, j = 0, max = 0, lect, tmp = 0, tot = 0;
    for(i=0; i<NBRE_SOMMETS; i++){
	tmp = 0;
	for(j=0; j<NBRE_SOMMETS; j++){
	    fscanf(f, "%d", &lect);
	    if(lect!=0){
		tot++;
		tmp++;
	    }
	}
	if(tmp > max){
	    max = tmp;
	}
    }
    *nbreMax = max;
    *nbreTot = tot/2;
    fseek(f, 0L, SEEK_SET);
    printf("max : %d, nbreTot : %d\n", *nbreMax, *nbreTot);
}



void lectureFichier(FILE* f, arete tabArete[]){
    unsigned int i = 0, j = 0, indTabArete = 0;
    int c = 0;
    char chaine[200];

    for(i=0; i<NBRE_SOMMETS; i++){
	for(j=0; j<i; j++){
	    fscanf(f, "%d", &c);
	    if(c!=0){
		arete a = {i, j, c, true};
		tabArete[indTabArete] = a;
		indTabArete++;
	    }
	}
	fgets(chaine, 200, f);
    }
}
