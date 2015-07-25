#include "liste_elem.h"

void nouvElem(S_elem *e){
    (*e).val = NULL;
    (*e).pos_val_poss = NULL;
    (*e).l_val_poss = NULL;
    (*e).l_elem_imp = creerListeElemImp();
}

liste_elem creerListeElem(){
    return NULL;
}

void ajoutElemElem(liste_elem* l, S_elem e){
    liste_elem nouveau = calloc(1,sizeof(struct liste_elem));
    nouveau->S_el = e;
    nouveau->suiv = *l;
    nouveau->prec = NULL;
    if(!estVideElem(*l)){
	(*l)->prec = nouveau;
    }
    *l = nouveau;
}

bool estVideElem(liste_elem l){
    return l==NULL;
}

void liberationElem(liste_elem l){
    liberationValPoss(&((l->S_el).l_val_poss));
    liberationElemImp(&((l->S_el).l_elem_imp));
    free(l);
}

