#include "liste_elem_imp.h"

liste_elem_imp creerListeElemImp(){
    return NULL;
}

bool estVideElemImp(liste_elem_imp l){
    return l == NULL;
}

void ajoutElemElemImp(liste_elem_imp *l, char *val){
    liste_elem_imp nouveau = calloc(1, sizeof(struct liste_elem_imp));
    nouveau->val = val;
    if(!estVideElemImp(*l)){
	nouveau->suiv = *l;
    }
    *l = nouveau;
}
void ajoutElemPos(liste_elem_imp *l, char *val){
    liste_elem_imp nouveau = calloc(1, sizeof(struct liste_elem_imp));
    nouveau->val = val;
    if(!estVideElemImp(*l)){
	nouveau->suiv = *l;
    }
    *l = nouveau;
}

void liberationElemImp(liste_elem_imp *l){
    liste_elem_imp p = *l;
    while(*l){
	p = *l;
	*l = (*l)->suiv;
	free(p);
    }
}
