#include "liste_elem.h"

void nouvElem(S_elem *e){
    (*e).pos.lig = 0;
    (*e).pos.col = 0;
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

void visuListeElem(liste_elem l){
    liste_elem p = l;
    while(!estVideElem(p)){
	visuElem(p->S_el);
	printf("\n");
	p = p->suiv;
    }
}

void visuElem(S_elem e){
    printf("elem => pos : lig : %d, col : %d, val : %d\n", e.pos.lig, e.pos.col, *(e).val);
    visuListeVal(e.l_elem_imp);
    visuListeValPoss(e.l_val_poss);
}

void visuTabHach(liste_elem l[NBRE_VAL_POSS]){
    int i = 0;
    int nbre_elem = 0;
    for(i=0; i<NBRE_VAL_POSS; i++){
	printf("elem a %d possibilitees : \n", i+1);
	liste_elem p = l[i];
	while(!estVideElem(p)){
	    nbre_elem++;
	    visuElem(p->S_el);
	    printf("\n");
	    p = p->suiv;
	}
	printf("\n");
    }
    printf("nbre d'element : %d\n", nbre_elem);
}

void liberationElem(liste_elem l){
    liberationValPoss(&((l->S_el).l_val_poss));
    liberationElemImp(&((l->S_el).l_elem_imp));
    free(l);
}

