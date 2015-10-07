#include "tri.h"

void trierTabArete(arete tabArete[], int nbreArete){
    qsort(tabArete, nbreArete, sizeof(arete), comparArete);
}

int comparArete(void const *a, void const *b){
    arete *pa = (arete*)a;
    arete *pb = (arete*)b;
    return pa->val - pb->val;
}


/*void triFusion(arete tab[]){
    division(tab, 0, NBRE_ARETE);
}

void division(arete tab[], int debut, int taille){
    printf("dans division => debut : %d, taille : %d => ", debut, taille);
    if(taille>1){
	printf("on entre\n");
	int newTaille = taille/2;
	division(tab, debut, newTaille);
	division(tab, debut+newTaille, newTaille);
	fusion(tab, debut, taille);
    }
    else{
	printf("on entre pas\n");
    }

}

void fusion(arete tab[], int debut, int taille){
    printf("dans fusion\n");
    int ind1 = debut, ind2 = debut+taille/2+1, indTot = 0;
    int endInd1 = debut+taille/2, endIndTot = debut+taille;
    arete *tabClone = cloneTab((taille));

    while(ind1<=endInd1 && ind2 <= endIndTot){
	if(tab[ind1].val > tab[ind2].val){
	    tabClone[indTot] = tab[ind2];
	    ind2++;
	}
	else{
	    tabClone[indTot] = tab[ind1];
	    ind1++;
	}
	indTot++;
    }
    printf("apres premiere boucle\n");
    while(ind1<=endInd1){
	tabClone[indTot] = tab[ind1];
	indTot++;
	ind1++;
    }

    while(ind2<=endIndTot){
	tabClone[indTot] = tab[ind2];
	ind2++;
	indTot++;
    }

    copieTab(tab, tabClone, debut, taille);
}

void copieTab(arete tab1[], arete tab2[], int debut, int taille){
    int i, j;
    for(i=debut, j=0; i<=debut+taille; i++, j++){
	tab1[i] = tab2[j];
    }
}

arete* cloneTab(int taille){
    arete *tab = calloc(taille, sizeof(arete));
    if(tab == NULL){
	fprintf(stderr, "allocation impossible, fichier %s, ligne %d\n", __FILE__, __LINE__);
	exit(0);
    }
    return tab;
}*/
