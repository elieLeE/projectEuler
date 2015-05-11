#include "nbre.h"

int nbre_integer(char puis){
    int i = 1, compt = 0;
    double limite_b = pow(10, puis-1);
    double limite_h = limite_b*10;
    double calcul = 0;

    while((calcul = pow(i, puis)) < limite_h){
	if(calcul >= limite_b){
	    compt++;
	}
	i++;
    }
    return compt;
}

