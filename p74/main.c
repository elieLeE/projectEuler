#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"
#include "nbre.h"
#include "algo.h"
#include "donnees.h"

/**
 *  algorithme
 *  pour i de 1 a TAILLE
 *  s <= sumDesFactorielsDigits de i
 *  tant que true
 *	si tabDone[s] != -1 ==> a ete fait 1 fois precedente
 *	    tailleBoucle += tabDone[s]
 *	    si tailleBoucle >= 60
 *		compt++
 *	    fin si
 *	    pour j de 0 a tailleBoucle
 *		tabDone[tabBoucle[i]] = tailleBoucle
 *		tailleBoucle--
 *	    fin pour
 *	    tailleBoucle <= 0
 *	    break
 *	sinon si s dans tabBoucle ==> fait dans la boucle actuelle
 *	    ind <= indice de s dans tabBoucle
 *	    si tailleBoucle-(indice+1) >=60
 *		compt++
 *	    fin si
 *	    si indice-1 >=60
 *		compt++
 *	    fin si
 *	    pour j de 0 a indice-1
 *		tabDone[tabBoucle[j]] = tailleBoucle
 *		tailleBoucle--
 *	    fin pour
 *	    pour j de indice+1 a tailleBoucle
 *		tabDone[tabBoucle[j]] = j
 *	    fin pour
 *	    tailleBoucle <= 0
 *	    break
 *	sinon 
 *	    tabBoucle[tailleBoucle] <= s
 *	    si tailleBoucle = tailleTabAc-1
 *		tabBoucle <= realloc(tailleTabAc*2)
 *	    fin si
 *	    tailleBoucle++
 *	    tabBoucle[tailleBoucle] <= -1
 *	    s <= sumDesFactorielsDigits de s
 *	fin si
 *  fin tant que
 *  */

int main(){

    int *nDone = (int*)my_malloc(TAILLE*sizeof(int));
    int boucleAc[1000];
    int i = 0, j = 0, k = 0, tailleBoucle = 0, ind, add;
    int compt = 0, n;

    for(i=0; i<TAILLE; i++){
	nDone[i] = -1;
    }

    for(i=1; i<LIMITE; i++){
	n = i;
	tailleBoucle = 0;
	boucleAc[0] = -1;
	while(true){
	    if((add = nDone[n]) != -1){
		tailleBoucle += add;
		if(tailleBoucle >= 60){
		    compt++;
		}
		remplissageTabDone(nDone, boucleAc, tailleBoucle);
		break;
	    }
	    else if((ind = nAlreadyDone(boucleAc, n))!=-1){
		if((tailleBoucle - (ind+1)) >= 60){
		    compt++;
		}
		if(ind-1 >= 60){
		    compt++;
		}
		k = tailleBoucle - ind;
		for(j=ind+1; j<tailleBoucle; k--, j++){
		    nDone[boucleAc[j]] = k;
		}
		for(j=0; j<ind; j++){
		    nDone[boucleAc[j]] = tailleBoucle;
		    tailleBoucle--;
		}
		break;
	    }
	    else{
		boucleAc[tailleBoucle] = n;
		tailleBoucle++;
		boucleAc[tailleBoucle] = -1;
		n = sumFactDigits(n);
	    }
	}
    }

    printf("%d\n", compt);
    free(nDone);

    return 0;
}
