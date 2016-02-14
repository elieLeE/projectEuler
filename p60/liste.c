#include "liste.h"

liste creerListe(){
    liste l = my_calloc(sizeof(struct liste));
    l->deb = my_calloc(sizeof(struct cell));
    (l->deb)->el.nbre = 3;
    (l->deb)->el.nbreDigit = 1;
    l->end = l->deb;
    return l;
}

void visuListe(cell l){
    cell p = l;
    while(p!=NULL){
	printf("(%d, %d), ", p->el.nbre, p->el.nbreDigit);
	p = p->suiv;
    }
    printf("\n");
}

void ajoutCell(cell *l, short nbre){
    cell nouv = my_calloc(sizeof(struct cell));
    nouv->suiv = NULL;
    (nouv->el).nbre = nbre;
    (nouv->el).nbreDigit = nbreDigit(nbre);
    (*l)->suiv = nouv;
    *l = (*l)->suiv;
}

void remplissageListe(cell *l){
    short i = 0;
    for(i=7; i<LIMITE; i+=2){
	if(isPrime(i)){
	    ajoutCell(l, i);
	}
    }
}
