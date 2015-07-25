#include "liste_val_poss.h"

liste_val_poss creerListeValPoss(){
    return NULL;
}

bool estVideValPoss(liste_val_poss l){
    return l==NULL;
}

void ajoutElemValPoss(liste_val_poss *l, char val){
    liste_val_poss nouveau = calloc(1, sizeof(struct liste_val_poss));
    nouveau->val = val;
    nouveau->suiv = *l;
    *l = nouveau;
}

void liberationValPoss(liste_val_poss *l){
    liste_val_poss p = *l;
    while(*l){
	p = *l;
	*l = (*l)->suiv;
	free(p);
    }
}

