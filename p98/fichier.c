#include "fichier.h"

bool lireMot(FILE* f, char *nextMot){
    if(feof(f)!=0){
	return false;
    }
    fgets(nextMot, 50, f);
    return true;
}

