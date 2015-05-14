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
    if(isEmpty(*l)){
	nouv->suiv = NULL;
    }
    else{
	nouv->suiv = *l;
    }
    *l = nouv;
}

void visuListePerm(l_perm l){
    l_perm p = l;
    while(p!=NULL){
	printf("%ld, ", p->nbre);
	p = p->suiv;
    }
}

