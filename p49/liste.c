#include "liste.h"

bool isEmpty(l_perm l){
    return l==NULL;
}

l_perm creerListe(){
    return NULL;
}

void ajoutElem(l_perm *l, long nbre){
    l_perm nouv = (l_perm )calloc(1, sizeof(struct l_perm));
    nouv->nbre = nbre;
    nouv->suiv = *l;
    *l = nouv;
}

void visuListePerm(l_perm l){
    l_perm p = l;
    while(p!=NULL){
	printf("%d, ", p->nbre);
	p = p->suiv;
    }
}

/*
 * determine si la liste suivante contient des elements pouvant etre solutions
 */;
bool isSol(l_perm p, int tab[3]){
    l_perm p1 = p, p2, p3;
    int dist = 0, dist2 = 0;
    char compteur = 1;
    bool continuer = true;
    while(p1!=NULL & continuer){
	tab[0] = p1->nbre;
	p2 = p1->suiv;
	while(p2!=NULL & continuer){
	    tab[1] = p2->nbre;
	    dist = p1->nbre - p2->nbre;
	    p3 = p2->suiv;
	    while(p3!=NULL){ 
		dist2 = (p2->nbre - p3->nbre);
		if((p2->nbre - p3->nbre) >=dist){
		    if(dist2 ==dist){
			tab[2] = p3->nbre;
			continuer = false;
		    }
		    break;
		}
		else{
		    p3 = p3->suiv;
		}
	    }
	    p2 = p2->suiv;
	}
	p1 = p1->suiv;
    }
    return !continuer;
}

