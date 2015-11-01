#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tab.h"

bool isSubStringDivisibility(int tab[]);

int main(){
    int t[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, t2[9][10];
    int compt = 1;
    int b, c, d, e, f, g, h, i, j;

    for(i=0; i<9; i++){
	copieTab(t2[i], t, 0);
    }

    j = 8;
    for(b=0; b<10; b++){
	copieTab(t2[1], t, 0);
	for(c=1; c<10; c++){
	    copieTab(t2[2], t, 0);
	    for(d=2; d<10; d++){
		copieTab(t2[3], t, 1);
		for(e=3; e<10; e++){
		    copieTab(t2[4], t, 2);
		    for(f=4; f<10; f++){
			copieTab(t2[5], t, 3);
			for(g=5; g<10; g++){
			    copieTab(t2[6], t, 4);
			    for(h=6; h<10; h++){
				copieTab(t2[7], t, 5);
				j = 8;
				for(i=7; i<10; i++){
/*				    if(compt==1000000){
					visuTab(t);
					return 0;
				    }*/
				    copieTab(t2[8], t, 6);
				    compt++;
				    visuTab(t);
				    echange(&t[8], &t[9]);
				    visuTab(t);
				    /*if(compt==1000000){
					visuTab(t);
					return 0;
				    }*/
				    compt++;
				    copieTab(t, t2[8], 6);
				    if(j<10){
					echange(&t[7], &t[j]);
				    }
				    j++;
				}

				copieTab(t, t2[7], 5);
				echange(&t[6], &t[h+1]);
			    }
			    copieTab(t, t2[6], 4);
			    echange(&t[5], &t[g+1]);
			}
			copieTab(t, t2[5], 3);
			echange(&t[4], &t[f+1]);
		    }
		    copieTab(t, t2[4], 2);
		    echange(&t[3], &t[e+1]);
		}
		copieTab(t, t2[3], 1);
		echange(&t[2], &t[d+1]);
	    }
	    copieTab(t, t2[2], 0);
	    echange(&t[1], &t[c+1]);
	}
	copieTab(t, t2[1], 0);
	echange(&t[0], &t[b+1]);
    }

    return 0;
}
