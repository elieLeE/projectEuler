#include "triplet.h"

void initTriplets(triplet *tabTri, int *tabInt){
    int i, j;
    for(i=0, j = NBRE_TRIPLETS; i<NBRE_TRIPLETS-1; i++, j++){
	tabTri[i].tab[0] = &tabInt[i];
	tabTri[i].tab[1] = &tabInt[j];
	tabTri[i].tab[2] = &tabInt[j+1];
    }
    tabTri[NBRE_TRIPLETS-1].tab[0] = &tabInt[NBRE_TRIPLETS-1];
    tabTri[NBRE_TRIPLETS-1].tab[1] = &tabInt[NBRE_DIGIT-1];
    tabTri[NBRE_TRIPLETS-1].tab[2] = &tabInt[NBRE_TRIPLETS];
}

void affTriplets(triplet *t){
    int i = 0;
    for(i=0; i<NBRE_TRIPLETS; i++){
	printf("triplet %d => ", i);
	affTriplet(t[i]);
    }
    printf("\n");
}

void affTriplet(triplet t){
    printf("(%d, %d, %d)\n", *(t.tab[0]), *(t.tab[1]), *(t.tab[2]));
}

int sumTriplet(triplet t){
    return *(t.tab[0]) + *(t.tab[1]) + *(t.tab[2]);
}

bool solPossible(triplet *t){
    int n = sumTriplet(t[0]);
    int i;
    for(i=0; i<NBRE_TRIPLETS; i++){
	if((*(t[i].tab[1])==10) || (*(t[i].tab[2])==10)){
	    return false;
	}
    }
    for(i=1; i<NBRE_TRIPLETS; i++){
	if(n!=sumTriplet(t[i])){
	    return false;
	}
    }
    return true;
}

int lowestExternalNode(triplet *t){
    int min = *(t[0].tab[0]), i, ind=0;
    for(i=1; i<NBRE_TRIPLETS; i++){
	if(min > *(t[i].tab[0])){
	    min = *(t[i].tab[0]);
	    ind = i;
	}
    }
    return ind;
}

int tripletToNbre(triplet t){
    return *(t.tab[0])*100+*(t.tab[1])*10+*(t.tab[2]);
}

double tripletsToNbre(triplet *t){
    int indMin = lowestExternalNode(t), i;
    double nbre = tripletToNbre(t[indMin]);
    for(i=indMin+1; i<NBRE_TRIPLETS; i++){
	if(*(t[i].tab[0])==10){
	    nbre*=10000;
	}
	else{
	    nbre*=1000;
	}
	nbre += tripletToNbre(t[i]);
    }
    for(i=0; i<indMin; i++){
	if(*(t[i].tab[0])==10){
	    nbre*=10000;
	}
	else{
	    nbre*=1000;
	}
	nbre += tripletToNbre(t[i]);
    }
    return nbre;
}

