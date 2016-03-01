#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main(){
    unsigned int tab[4] = {0}, tabMax[4] = {0};
    unsigned int longSet = 0, maxLongestSet = 0;

    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 4;

    while((tab[0]<=6) || (tab[1] <= 7) || (tab[2] <= 8) || (tab[3] <= 9)){
	while((tab[1] <= 7) || (tab[2] <= 8) || (tab[3] <= 9)){
	    while((tab[2] <= 8) || (tab[3] <= 9)){
		while(tab[3]<=9){
		    if((longSet = longestSet(tab)) > maxLongestSet){
			tabMax[0] = tab[0];
			tabMax[1] = tab[1];
			tabMax[2] = tab[2];
			tabMax[3] = tab[3];
			maxLongestSet = longSet;
		    }
		    tab[3]++;
		}
		tab[2]++;
		tab[3] = tab[2]+1;
	    }
	    tab[1]++;
	    tab[2] = tab[1]+1;
	    tab[3] = tab[2]+1;
	}
	tab[0]++;
	tab[1] = tab[0]+1;
	tab[2] = tab[1]+1;
	tab[3] = tab[2]+1;
    }

    printf("%d%d%d%d\n", tabMax[0], tabMax[1], tabMax[2], tabMax[3]);

    return 0;
}
