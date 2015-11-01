#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tab.h"

bool isSubStringDivisibility(int tab[]);

int main(){
    int t[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, t2[9][10];
    int compt = 1;
    int b, c, d, e, f, g, h, i, j;
    long sum = 0.0;

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
		    if((t[1]*100+t[2]*10+t[3])%2!=0){
			echange(&t[3], &t[e+1]);
			continue;
		    }
		    for(f=4; f<10; f++){
			copieTab(t2[5], t, 3);
			if((t[2]*100+t[3]*10+t[4])%3!=0){
			    echange(&t[4], &t[f+1]);
			    continue;
			}
			for(g=5; g<10; g++){
			    copieTab(t2[6], t, 4);
			    if((t[3]*100+t[4]*10+t[5])%5!=0){
				echange(&t[5], &t[g+1]);
				continue;
			    }
			    for(h=6; h<10; h++){
				copieTab(t2[7], t, 5);
				if((t[4]*100+t[5]*10+t[6])%7!=0){
				    echange(&t[6], &t[h+1]);
				    continue;
				}
				j = 8;
				for(i=7; i<10; i++){
				    if((t[5]*100+t[6]*10+t[7])%11==0){
					if(((t[6]*100+t[7]*10+t[8])%13==0) && ((t[7]*100+t[8]*10+t[9])%17==0)){
					    copieTab(t2[8], t, 6);
					    sum+=tabToNbre(t);
					}
					echange(&t[8], &t[9]);
					if(((t[6]*100+t[7]*10+t[8])%13==0) && ((t[7]*100+t[8]*10+t[9])%17==0)){
					    copieTab(t2[8], t, 6);
					    visuTab(t);
					}
					copieTab(t, t2[8], 6);
				    }
				    if(i+1<10){
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
    printf("sum => %ld\n", sum);

    return 0;
}
