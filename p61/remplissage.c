#include "remplissage.h"

void remplissage(l_elem *l, l_tabhach tabhach[5][100]){
    int dist = 2, a_dist = 1, i = 0;
    for(i=0; i<5; i++, dist++, a_dist++){
	remplissageNbre(tabhach[i], dist, a_dist);
    }
    remplissageListeNbreOctagonal(l);
}

void remplissageListeNbreOctagonal(l_elem *l){
    (*l).deb = creerListe();
    (*l).end = (*l).deb;
    int left_partie = 0, right_partie = 1;
    int dist = 7;
    int ajout_dist = 6, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    ajoutElem(l, right_partie, left_partie);
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
} 

void remplissageNbre(l_tabhach tabhach[100], int dist_init, int a_dist){
    int left_partie = 0, right_partie = 1;
    int dist = dist_init;
    int ajout_dist = a_dist, retenue = 0;
    initTabHach(tabhach);
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    ajoutElemTabHach(&tabhach[right_partie], left_partie);
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
} 
