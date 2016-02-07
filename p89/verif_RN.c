#include "verif_RN.h"

unsigned int nbreCarSaved(char *romanNumeral){
    unsigned int rep = 1, i = 1, taille = strlen(romanNumeral), compt = 0;
    char previousCar = romanNumeral[0], prePrevious = 0;
    while(i<taille){
	if(romanNumeral[i]=='M'){
	    previousCar = romanNumeral[i];
	    i++;
	    continue;
	}
	if(romanNumeral[i] == previousCar){
	    rep++;
	    if(rep == 4){
		if(doubleSaved(previousCar, prePrevious)){
		    compt+=3;
		}
		else{
		    compt+=2;
		}
		rep = 0;
	    }
	}
	else{
	    prePrevious = previousCar;
	    previousCar = romanNumeral[i];
	    rep = 1;
	}
	i++;
    }
    return compt;
}

bool doubleSaved(char pre1, char pre2){
    switch(pre1){
	case 'I':
	    return (pre2=='V');
	case 'V':
	    return (pre2=='X');
	case 'X':
	    return (pre2=='L');
	case 'L':
	    return (pre2=='C');
	case 'C':
	    return (pre2=='D');
	}
    return false;
}


