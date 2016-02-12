#include "matrice.h"

void affMatrice(unsigned int** matrice){
    int i, j;
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    printf("%d, ", matrice[i][j]);
	}
	printf("\n");
    }
}

unsigned int minAB(unsigned int a, unsigned int b){
    if(a>b){
	return b;
    }
    return a;
}

unsigned int minABCD(unsigned int *tab){
    int i;
    unsigned int min = tab[0];
    for(i=1; i<4; i++){
	if(min > tab[i]){
	    min = tab[i];
	}
    }
    return min;
}

int searchWay(unsigned int** matrice, bool tabB[][TAILLE_MATRICE], pos *posActuelle, pos *obj, int min, int valAc){
    if(tabB[posActuelle->lig][posActuelle->col]){
	return BIG;
    }
    if((posActuelle->lig == obj->lig) && (posActuelle->col == obj->col)){
	return SMALL;
    }
    valAc = valAc + matrice[posActuelle->lig][posActuelle->col];
    if(valAc > min){
	return BIG;
    }
    tabB[posActuelle->lig][posActuelle->col] = true;
    unsigned int tab[4];
    pos newPos;
    newPos.lig = posActuelle->lig + 1;
    newPos.col = posActuelle->col; 
    tab[0] = searchWay(matrice, tabB, &newPos, obj, min, valAc+matrice[posActuelle->lig][posActuelle->col]);

    //tabB modifie dans searchWay ==> pose pb pour les autres appels de searchWay
    newPos.lig = posActuelle->lig-1;
    tab[1] = searchWay(matrice, tabB, &newPos, obj, min, valAc+matrice[posActuelle->lig][posActuelle->col]);

    newPos.lig = posActuelle->lig;
    newPos.col = posActuelle->col-1;
    tab[2] = searchWay(matrice, tabB, &newPos, obj, min, valAc+matrice[posActuelle->lig][posActuelle->col]);

    newPos.col = posActuelle->col+1;
    tab[3] = searchWay(matrice, tabB, &newPos, obj, min, valAc+matrice[posActuelle->lig][posActuelle->col]);
    return minABCD(tab)+matrice[posActuelle->lig][posActuelle->col];
    
}

unsigned int pccAToB(unsigned int** matrice, bool tabB[][TAILLE_MATRICE], pos *dep, pos *obj){
    unsigned int min = BIG;
    pos newPos;

    newPos.lig = dep->lig + 1;
    newPos.col = dep->col; 
    min = minAB(min, searchWay(matrice, tabB, &newPos, obj, min, matrice[dep->lig][dep->col]));

    //tabB modifie dans searchWay ==> pose pb pour les autres appels de searchWay
    newPos.lig = dep->lig-1;
    min = minAB(min, searchWay(matrice, tabB, &newPos, obj, min, matrice[dep->lig][dep->col]));

    newPos.lig = dep->lig;
    newPos.col = dep->col-1;
    min = minAB(min, searchWay(matrice, tabB, &newPos, obj, min, matrice[dep->lig][dep->col]));

    newPos.col = dep->col+1;
    min = minAB(min, searchWay(matrice, tabB, &newPos, obj, min, matrice[dep->lig][dep->col]));
    return min;
    
}

void initTabB(bool tabB[][TAILLE_MATRICE], int n){
    int i, j;
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    if(i+j>n){
	        tabB[i][j] = false;
	    }
	    else{
	        tabB[i][j] = true;
	    }
	}
    }
}

unsigned int pccToB(unsigned int** matrice, pos *obj){
    int n = obj->lig+obj->col-1;
    static bool tabB[TAILLE_MATRICE][TAILLE_MATRICE];
    pos dep;
    dep.col = n;
    unsigned int min = BIG;
    for(dep.lig=0; dep.lig<n; dep.lig++, dep.col--){
	min = minAB(min, pccAToB(matrice, tabB, &dep, obj));
    }
    return min;
}

unsigned int shorterWay(unsigned int** matrice){
    unsigned int** tab;
    allocTab2D(&tab);

    int i;
    unsigned int min;
    pos dep;
    tab[0][0] = matrice[0][0];

    for(i=1; i<TAILLE_MATRICE; i++){
	dep.col = i;
	for(dep.lig=0; dep.lig<=i; dep.lig++, dep.col--){
	    tab[dep.lig][dep.col] = pccToB(matrice, &dep);
	}
    }
    for(i=TAILLE_MATRICE-1; i>=0; i--){
	dep.col = i+1;
	for(dep.lig=1; dep.lig<=i; dep.lig++, dep.col--){
	    tab[dep.lig][dep.col] = pccToB(matrice, &dep);
	}
    }
    min = tab[TAILLE_MATRICE-1][TAILLE_MATRICE-1];
    liberation(tab);
    return min;
}
