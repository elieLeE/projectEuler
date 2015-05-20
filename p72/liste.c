#include "liste.h"

liste creerListe(){
    return NULL;
}

void visuListe(liste l){
    liste p = l;
    while(p!=NULL){
	printf("%d, ", p->nbre);
	p = p->suiv;
    }
}

void ajoutListe(liste *l, int nbre){
    liste nouv = (struct liste *)calloc(1, sizeof(struct liste));
    nouv->nbre = nbre;
    nouv->suiv = NULL;
    (*l)->suiv = nouv;
    *l = nouv;
}

void remplissageListe(liste *l){
    int i = 0;
    *l = (liste)calloc(1, sizeof(struct liste));
    (*l)->suiv = NULL;
    (*l)->nbre = 2;
    liste p = *l;
    for(i=3; i<=NBRE_MAX; i+=2){
	if(isPrime(i)){
	    ajoutListe(&p, i);
	}
    }
}




