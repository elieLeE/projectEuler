#include "algo.h"

liste_elem initTableHachage(char **grille){
    char i = 0, j = 0, nbre_val_poss;
    S_elem e;
    liste_elem file_prio;
    liste_elem l[9];

    for(i=0; i<NBRE_VAL_POSS; i++){
	l[i] = creerListeElem();
    }
    for(i=0; i< NBRE_LIGNE; i++){
	for(j=0; j<NBRE_COL; j++){
	    if(grille[i][j] == 0){
		nouvElem(&e);
		e.val = &grille[i][j];
		nbre_val_poss = nbreDeValPoss(grille, &e, i, j);
		e.pos_val_poss = e.l_val_poss;
		ajoutElemElem(&(l[nbre_val_poss-1]), e);
	    }
	}
    }
    liaisonTabHach(l, &file_prio);
    return file_prio;
}

void liaisonTabHach(liste_elem *tab_hach, liste_elem *file_prio){
    char pos = 0, pos2 = 0;
    liste_elem p = tab_hach[0];
    bool faire_liaison = false;
    pos = searchFirstListeNonVide(tab_hach, file_prio);
    for(pos2=pos+1; pos2<NBRE_VAL_POSS; pos2++){
	if(!estVideElem(tab_hach[pos2])){
	    searchLastElem(tab_hach[pos], &p);
	    p->suiv = tab_hach[pos2];
	    tab_hach[pos2]->prec = p;
	    pos = pos2;
	}
    }
}

char searchFirstListeNonVide(liste_elem *tab_hach, liste_elem *first_elem){
    liste_elem p = tab_hach[0];
    int pos = 0;
    while(estVideElem(tab_hach[pos])){
	pos++;
    }
    *first_elem = tab_hach[pos];
    return pos;
}


void searchLastElem(liste_elem l, liste_elem *last_elem){
    liste_elem p = l;
    while(!estVideElem(p->suiv)){
	p = p->suiv;
    }
    *last_elem = p;
}

void remplissageUneSolution(liste_elem l){
    liste_elem p = l;
    while(!estVideElem(p)){
	*((p->S_el).val) = ((p->S_el).l_val_poss->val);
	p = p->suiv;
    }
}

void resolutionSudoku(liste_elem file_prio){
    liste_elem p = file_prio;
    bool sens = true;
    while(true){
	sens = nextRemplissage(&(p->S_el));
	if(sens){
	    p = p ->suiv;
	}
	else{
	    p = p->prec;
	}
	if(p == NULL){
	    return ;
	}
    }
}

bool nextRemplissage(S_elem* e){
    liste_val_poss p = (*e).pos_val_poss;
    while(!estVideValPoss(p)){
	if(valPrise((*e).l_elem_imp, p->val)){
	    p = p->suiv;
	}
	else{
	    *((*e).val) = p->val;
	    (*e).pos_val_poss = p->suiv;
	    return true;
	}
    }
    *((*e).val) = 0;
    (*e).pos_val_poss = (*e).l_val_poss;
    return false;
}

bool valPrise(liste_elem_imp l, char val){
    liste_elem_imp p = l;
    while(!estVideElemImp(p)){
	if(*(p->val) == val){
	    return true;
	}
	p = p->suiv;
    }
    return false;
}

void liberationFilePrio(liste_elem *l){
    liste_elem p = *l;
    while(!estVideElem(*l)){
	p = *l;
	*l = (*l)->suiv;
	liberationElem(p);
    }
}

