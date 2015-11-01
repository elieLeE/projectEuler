#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tab.h"
#include "triplet.h"

int main(){
    int t[NBRE_DIGIT], t2[9][NBRE_DIGIT];
    double maxTriplet = 0, n;
    int b, c, d, e, f, g, h, i;
    triplet gon[NBRE_TRIPLETS];

    initTab(t);
    /*printf("tab => ");
    visuTab(t);*/
    initTriplets(gon, t);

    //n = tripletsToNbre(gon);
    /*affTriplets(gon);
    printf("nbre : %ld\n", tripletsToNbre(gon));*/

    for(i=0; i<NBRE_DIGIT; i++){
	copieTab(t2[i], t, 0);
    }

    for(b=0; b<NBRE_DIGIT; b++){
	copieTab(t2[1], t, 0);
	for(c=1; c<NBRE_DIGIT; c++){
	    copieTab(t2[2], t, 0);
	    for(d=2; d<NBRE_DIGIT; d++){
		copieTab(t2[3], t, 1);
		for(e=3; e<NBRE_DIGIT; e++){
		    copieTab(t2[4], t, 2);
		    for(f=4; f<NBRE_DIGIT; f++){
			copieTab(t2[5], t, 3);
			for(g=5; g<NBRE_DIGIT; g++){
			    copieTab(t2[6], t, 4);
			    for(h=6; h<NBRE_DIGIT; h++){
				copieTab(t2[7], t, 5);
				for(i=7; i<NBRE_DIGIT; i++){
				    //visuTab(t);
				    if(solPossible(gon)){
					n = tripletsToNbre(gon);
					/*printf("%lf\n", n);
					affTriplets(gon);*/
					if(n>maxTriplet){
					    maxTriplet = n;
					}
				    }
				    copieTab(t2[8], t, 6);
				    echange(&t[8], &t[9]);
				    if(solPossible(gon)){
					n = tripletsToNbre(gon);
					/*printf("%lf\n", n);
					affTriplets(gon);*/
					if(n>maxTriplet){
					    maxTriplet = n;
					}
				    }
				    //visuTab(t);
				    copieTab(t, t2[8], 6);
				    if((i+1)<NBRE_DIGIT){
					echange(&t[7], &t[i+1]);
				    }
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
    printf("maxTriplet => %lf\n", maxTriplet);

    return 0;
}

