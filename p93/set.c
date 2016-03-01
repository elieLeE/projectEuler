#include "set.h"

unsigned int longestSet(unsigned int *tabDigits){
    bool tabVal[TAILLE_TAB] = {false};
    bool tabB[4] = {false};
    unsigned int i;

    calculSet(tabDigits, 0.0, tabVal, tabB, 0);

    i = 1;
    while(tabVal[i]){
	i++;
    }
    return i-1;
}

void calculSet(unsigned int *tab, double val, bool *tabVal, bool *tabB, unsigned int numStep){
    unsigned int i;
    if(numStep == 0){
	for(i=0; i<4; i++){
	    tabB[i] = true;
	    calculSet(tab, (double)tab[i], tabVal, tabB, 1);
	    tabB[i] = false;
	}
    }
    else if(numStep < 4){
	unsigned int j;
	double sauv = val;
	double add; 
	double sub;
	for(i=0; i<4; i++){
	    if(!tabB[i]){
		tabB[i] = true;

		calculSet(tab, sauv+tab[i], tabVal, tabB, numStep+1);
		calculSet(tab, sauv/tab[i], tabVal, tabB, numStep+1);
		calculSet(tab, sauv-tab[i], tabVal, tabB, numStep+1);
		calculSet(tab, sauv*tab[i], tabVal, tabB, numStep+1);

		tabB[i] = false;
		for(j=0; j<4; j++){
		    if(!tabB[j] && (j!=i)){
			add = (double)(tab[i]+tab[j]);
			sub = (double)tab[i] - (double)tab[j];
		    }
		}
		calculSet(tab, sauv*add, tabVal, tabB, 4);
		calculSet(tab, sauv*sub, tabVal, tabB, 4);
		calculSet(tab, sauv/add, tabVal, tabB, 4);
		calculSet(tab, sauv/sub, tabVal, tabB, 4);
	    }
	}
    }
    else{
	if((val > 0) && (val == floor(val))){
	    tabVal[(unsigned int)val] = true;
	}
    }
}
