#include "verif_RN.h"

unsigned int nbreCarSaved(char *romanNumeral){
    unsigned int rep = 1, i = 1, taille = strlen(romanNumeral), compt = 0;
    char previousCar = romanNumeral[0];
    //printf("taille : %d\n", taille);
    while(i<taille){
	printf("%c => ", romanNumeral[i]);
	if(romanNumeral[i]=='M'){
	    previousCar = romanNumeral[i];
	    i++;
	    continue;
	}
	if(romanNumeral[i] == previousCar){
	    rep++;
	    printf("repetition ==> %d", rep);
	    if(rep == 4){
		compt+=2;
		rep = 0;
	    }
	}
	else{
	    previousCar = romanNumeral[i];
	    rep = 1;
	}
	printf("\n");
	i++;
    }
    return compt;
}

