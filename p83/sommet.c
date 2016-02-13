#include "sommet.h"

void initSommet(sommet** s, unsigned int** matrice, pos p){
    s[p.lig][p.col].coutSom = matrice[p.lig][p.col];
    s[p.lig][p.col].coutChemin = 0;
    s[p.lig][p.col].e = NON_ATTEIGNABLE;
    s[p.lig][p.col].p = p;

    if(p.lig == 0){
	if(p.col == 0){
	    s[0][0].nbreVoisins = 2;
	    s[0][0].voisins[0] = &s[1][0];
	    s[0][0].voisins[1] = &s[0][1];
	}
	else if(p.col == TAILLE_MATRICE -1){
	    s[0][TAILLE_MATRICE-1].nbreVoisins = 2;
	    s[0][TAILLE_MATRICE-1].voisins[0] = &s[0][TAILLE_MATRICE-2];
	    s[0][TAILLE_MATRICE-1].voisins[1] = &s[1][TAILLE_MATRICE-1];
	}
	else {
	    s[0][p.col].nbreVoisins = 3;
	    s[0][p.col].voisins[0] = &s[0][p.col-1];
	    s[0][p.col].voisins[1] = &s[0][p.col+1];
	    s[0][p.col].voisins[2] = &s[1][p.col];
	}
    }
    else if(p.lig == TAILLE_MATRICE-1){
	if(p.col == 0){
	    s[TAILLE_MATRICE-1][0].nbreVoisins = 2;
	    s[TAILLE_MATRICE-1][0].voisins[0] = &s[TAILLE_MATRICE-2][0];
	    s[TAILLE_MATRICE-1][0].voisins[1] = &s[TAILLE_MATRICE-1][1];
	}
	else if(p.col == TAILLE_MATRICE -1){
	    s[TAILLE_MATRICE-1][TAILLE_MATRICE-1].nbreVoisins = 2;
	    s[TAILLE_MATRICE-1][TAILLE_MATRICE-1].voisins[0] = &s[TAILLE_MATRICE-1][TAILLE_MATRICE-2];
	    s[TAILLE_MATRICE-1][TAILLE_MATRICE-1].voisins[1] = &s[TAILLE_MATRICE-2][TAILLE_MATRICE-1];
	}
	else {
	    s[TAILLE_MATRICE-1][p.col].nbreVoisins = 3;
	    s[TAILLE_MATRICE-1][p.col].voisins[0] = &s[TAILLE_MATRICE-1][p.col-1];
	    s[TAILLE_MATRICE-1][p.col].voisins[1] = &s[TAILLE_MATRICE-1][p.col+1];
	    s[TAILLE_MATRICE-1][p.col].voisins[2] = &s[TAILLE_MATRICE-2][p.col];
	}
    }
    else{
	if(p.col == 0){
	    s[p.lig][0].nbreVoisins = 3;
	    s[p.lig][0].voisins[0] = &s[p.lig-1][0];
	    s[p.lig][0].voisins[1] = &s[p.lig+1][0];
	    s[p.lig][0].voisins[2] = &s[p.lig][1];
	}
	else if(p.col == TAILLE_MATRICE -1){
	    s[p.lig][TAILLE_MATRICE-1].nbreVoisins = 3;
	    s[p.lig][TAILLE_MATRICE-1].voisins[0] = &s[p.lig-1][TAILLE_MATRICE-1];
	    s[p.lig][TAILLE_MATRICE-1].voisins[1] = &s[p.lig+1][TAILLE_MATRICE-1];
	    s[p.lig][TAILLE_MATRICE-1].voisins[2] = &s[p.lig][TAILLE_MATRICE-2];
	}
	else{
	    s[p.lig][p.col].nbreVoisins = 4;
	    s[p.lig][p.col].voisins[0] = &s[p.lig-1][p.col];
	    s[p.lig][p.col].voisins[1] = &s[p.lig+1][p.col];
	    s[p.lig][p.col].voisins[2] = &s[p.lig][p.col-1];
	    s[p.lig][p.col].voisins[3] = &s[p.lig][p.col+1];
	}
    }
}

void affSommet(sommet *s){
    int i;
    printf("(%d, %d) => %d ==> ", (s->p).lig, (s->p).col, s->coutSom);
    for(i=0; i<s->nbreVoisins; i++){
	printf("%d, ", (s->voisins[i])->coutSom);
    }
    printf("\n");
}

