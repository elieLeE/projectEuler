#include "graphe.h"

void remplissageGraphe(sommet** g, unsigned int **matrice){
    int i, j;
    pos p;
    for(i=0; i<TAILLE_MATRICE; i++){
	p.lig = i;
	for(j=0; j<TAILLE_MATRICE; j++){
	    p.col = j;
	    initSommet(g, matrice, p);
	}
    }
}

void affGraphe(sommet** g){
    int i, j;
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    printf("(%d, %d) => ", i, j);
	    affSommet(&g[i][j]);
	}
	printf("\n");
    }
}

sommet* nextSommet(sommet** g){
    int i, j;
    unsigned int min = BIG;
    sommet *s;
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    if((g[i][j].e == ATTEIGNABLE) && (min > g[i][j].coutChemin)){
		min = g[i][j].coutChemin;
		s = &g[i][j];
	    }
	}
    }
    return s;
}

void miseAJourGraphe(sommet *s){
    int i;
    unsigned int newChemin;
    s->e = ADDED;
    for(i=0; i<s->nbreVoisins; i++){
	switch((s->voisins[i])->e){
	    case NON_ATTEIGNABLE :
		(s->voisins[i])->e = ATTEIGNABLE;
		(s->voisins[i])->coutChemin = (s->voisins[i])->coutSom + s->coutChemin;
		break;

	    case ATTEIGNABLE :
		newChemin = (s->voisins[i])->coutSom + s->coutChemin;
		if(newChemin < (s->voisins[i])->coutChemin){
		    (s->voisins[i])->coutChemin = newChemin;
		}
	}
    }
}

void affSommetAdded(sommet** g){
    int i, j;
    printf("sommet added : ");
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    if(g[i][j].e == ADDED){
		printf("(%d, %d) => %d/%d, ", g[i][j].p.lig, g[i][j].p.col, g[i][j].coutSom, g[i][j].coutChemin);
	    }
	}
    }
    printf("\n");
}

void affNextSomPossible(sommet** g){
    int i, j;
    printf("sommet atteignable : ");
    for(i=0; i<TAILLE_MATRICE; i++){
	for(j=0; j<TAILLE_MATRICE; j++){
	    if(g[i][j].e == ATTEIGNABLE){
		printf("(%d, %d) => %d-%d, ", g[i][j].p.lig, g[i][j].p.col, g[i][j].coutSom, g[i][j].coutChemin);
	    }
	}
    }
    printf("\n");
}

unsigned int shorterWay(unsigned int** matrice){
    sommet** grapheInit;
    sommet *s;
    unsigned int min;

    allocGraphe(&grapheInit);
    remplissageGraphe(grapheInit, matrice);

    grapheInit[0][0].e = ATTEIGNABLE;
    grapheInit[0][0].coutChemin = grapheInit[0][0].coutSom;

    do{
	s = nextSommet(grapheInit);
	miseAJourGraphe(s);
    }while(((s->p).lig != TAILLE_MATRICE-1) || ((s->p).col != TAILLE_MATRICE-1));
	
    min = grapheInit[TAILLE_MATRICE-1][TAILLE_MATRICE-1].coutChemin;
    liberationGraphe(grapheInit);
    return min;
}

