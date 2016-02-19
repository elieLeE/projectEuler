#include "liste.h"

liste* creerListe(){
    return NULL;
}

bool listeEmpty(liste *l){
    return (l==NULL);
}

void visuListe(liste *l, void (*visuElement)(void *data)){
    liste *p = l;
    while(!listeEmpty(p)){
	(*visuElement)(p->data);
	p = p->suiv;
    }
    printf("\b\b \n");
}

void addElementFirst(liste** l, void* data, int tailleData){
    liste* new = my_calloc(sizeof(struct liste));
    new->data = my_calloc(sizeof(tailleData));
    memcpy(new->data, data, tailleData);
    new->suiv = *l;
    *l = new;
}

void addElementLast(liste *l, void* data, int tailleData){
    liste* p = l;
    liste* new = my_calloc(sizeof(struct liste));
    new->data = my_calloc(tailleData);
    memcpy(new->data, data, tailleData);
    new->suiv = NULL;
    while(!listeEmpty(p->suiv)){
	p = p->suiv;
    }
    p->suiv = new;
}

void removeFirstElement(liste **l){
    liste *p = *l;
    *l = (*l)->suiv;
    free(p->data);
    free(p);
}

void removeLastElement(liste* l){
    liste* p = l;
    while(!listeEmpty(p->suiv)){
	//printf("%d\n", *((int *)p->data));
	p = p->suiv;
    }
    printf("%d\n", *(int *)p->data);
    //free(p->data);
    printf("ici\n");
    free(p);
    printf("ici 2\n");
}

void freeListe(liste** l){
    while(!listeEmpty(*l)){
	removeFirstElement(l);
    }
}

