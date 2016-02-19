#include "liste_elem_imp.h"

liste_elem_imp creerListeElemImp(){
    return NULL;
}

bool estVideElemImp(liste_elem_imp l){
    return l == NULL;
}

void ajoutElemElemImp(liste_elem_imp *l, char *val, S_pos pos){
    liste_elem_imp nouveau = calloc(1, sizeof(struct liste_elem_imp));
    nouveau->val = val;
    nouveau->pos = pos;
    if(!estVideElemImp(*l)){
	nouveau->suiv = *l;
    }
    *l = nouveau;
}
void ajoutElemPos(liste_elem_imp *l, char *val, S_pos pos){
    liste_elem_imp nouveau = calloc(1, sizeof(struct liste_elem_imp));
    nouveau->val = val;
    nouveau->pos = pos;
    if(!estVideElemImp(*l)){
	nouveau->suiv = *l;
    }
    *l = nouveau;
}

void visuListeVal(liste_elem_imp l){
    liste_elem_imp p = l;
    printf("elem impactant : ");
    while(!estVideElemImp(p)){
	printf("(%d, %d, %d), ", p->pos.lig, p->pos.col, *(p->val));
	p = p->suiv;
    }
    printf("\n");
}

void visuListeElemImp(liste_elem_imp l){
    liste_elem_imp p = l;
    printf("elem impactant : ");
    while(!estVideElemImp(p)){
	printf("(%d, %d), ", p->pos.lig, p->pos.col);
	p = p->suiv;
    }
    printf("\n");
}

void liberationElemImp(liste_elem_imp *l){
    liste_elem_imp p = *l;
    while(*l){
	p = *l;
	*l = (*l)->suiv;
	free(p);
    }
}
