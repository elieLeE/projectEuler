#include "liste.h"

bool isEmpty(c_elem l){
    return l==NULL;
}

void ajoutElem(l_elem *l, char right, char left){
    c_elem nouv = (c_elem )calloc(1, sizeof(struct c_elem));
    nouv->left = left;
    nouv->right = right;
    nouv->suiv = NULL;
    if(isEmpty(l->deb)){
	l->deb = nouv;
	l->end = nouv;
    }
    else{
	l->end->suiv = nouv;
	l->end = l->end->suiv;
    }
}

c_elem creerListe(){
    return NULL;
}

void visuListe(c_elem l, char *name){
    printf("%s\n", name);
    c_elem p = l;
    while(!isEmpty(p)){
	printf("(%d, %d) ", p->left, p->right);
	p = p->suiv;
    }
    printf("\n");
}


