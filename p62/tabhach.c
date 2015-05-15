#include "tabhach.h"

void initTabHach(l_tabhach tab[LIMITE_TAB]){
    char i = 0;
    for(i=0; i<LIMITE_TAB; i++){
	tab[i] = NULL;
    }
}

bool tabHachEmpty(l_tabhach t){
    return t == NULL;
}

void visuTabHach(l_tabhach tab[LIMITE_TAB]){
    char i = 0;
    for(i=0; i<LIMITE_TAB; i++){
	printf("tab[%d] => ", i);
	visuL(tab[i]);
	printf("\n");
    }
    printf("\n");
}

void visuL(l_tabhach l){
    l_tabhach p = l;
    if(p==NULL){
	printf("vide");
    }
    else{
	while(p!=NULL){
	    printf("\n\t");
	    visuListePerm(p->perm);
	    p = p->suiv;
	}
    }
}

bool permutationOK(char *tab1, char *tab2){
    char i = 0;
    for(i=0; i<10; i++){
	if(tab1[i] != tab2[i]){
	    return false;
	}
    }
    return true;
}

l_tabhach findElem(l_tabhach l, char *tab){
    char i = 0;
    l_tabhach p = l;
    while(p!=NULL){
	if(permutationOK(tab, p->tab)){
	    return p;
	}
	else{
	    p = p->suiv;
	}
    }
    return NULL;
}

l_tabhach ajoutElemTabHach(l_tabhach *l, long nbre, char* tab){
    l_tabhach p = findElem(*l, tab);
    if(p==NULL){
	l_tabhach nouv = (l_tabhach )calloc(1, sizeof(struct l_tabhach));
	nouv->tab = tab;
	nouv->nbre_perm = 1;
	ajoutElem(&(nouv->perm), nbre);
	if(tabHachEmpty(*l)){
	    nouv->suiv = NULL;
	}
	else{
	    nouv->suiv = *l;
	}
	*l = nouv;
	return *l;
    }
    else{
	(p->nbre_perm)++;
	free(tab);
	ajoutElem(&(p->perm), nbre);
	return p;
    } 
}

