#include "tabhach.h"

void initTabHach(l_tabhach tab[100]){
    char i = 0;
    for(i=0; i<100; i++){
	tab[i] = NULL;
    }
}

bool tabHachEmpty(l_tabhach t){
    return t == NULL;
}

void visuTabHach(l_tabhach tab[100], char *name){
    char i = 0;
    printf("%s\n", name);
    for(i=0; i<100; i++){
	visuL(tab[i]);
    }
    printf("\n");
}

void visuL(l_tabhach l){
    l_tabhach p = l;
    while(p!=NULL){
	visuListePerm(p->perm);
	printf("\n");
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
    printf("dans findElem\n");
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

void ajoutElemTabHach(l_tabhach *l, long nbre, char* tab){
    printf("dans ajoutElemTabHach\n");
    l_tabhach p = findElem(*l, tab);
    printf("dans ajoutElemTabHach 2\n");
    if(p==NULL){
	printf("dans le if\n");
	l_tabhach nouv = (l_tabhach )calloc(1, sizeof(struct l_tabhach));
	nouv->tab = tab;
	nouv->perm = NULL;
	if(tabHachEmpty(*l)){
	    nouv->suiv = NULL;
	}
	else{
	    nouv->suiv = *l;
	}
    }
    else{
	printf("dans le else\n");
	free(tab);
	ajoutElem(&(p->perm), nbre);
    }
}

