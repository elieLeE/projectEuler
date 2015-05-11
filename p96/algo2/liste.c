#include "liste.h"

S_liste creerListe(){
    return NULL;
}

bool estVide(S_liste l){
    return l == NULL;
}

void ajoutElem(S_liste *l, char *val){
    S_liste nouveau = calloc(1, sizeof(struct cell));
    nouveau->val = val;
    if(!estVide(*l)){
	nouveau->suiv = *l;
    }
    *l = nouveau;
}
void ajoutElemPos(S_liste *l, char *val, S_pos pos){
    S_liste nouveau = calloc(1, sizeof(struct cell));
    nouveau->val = val;
    nouveau->pos = pos;
    if(!estVide(*l)){
	nouveau->suiv = *l;
    }
    *l = nouveau;
}

void visuListeVal(S_liste l){
    S_liste p = l;
    while(!estVide(p)){
	printf("%d ", *(p->val));
	p = p->suiv;
    }
    printf("\n");
}

void visuBlocs(S_liste blocs[NBRE_BLOC]){
    char i = 0;
    for(i=0; i<NBRE_BLOC; i++){
	visuListeVal(blocs[i]);
    }
}

void visuListePos(S_liste l){
    S_liste p = l;
    while(!estVide(p)){
	printf("(%d, %d), ", p->pos.i, p->pos.j);
	p = p->suiv;
    }
    printf("\n");
}

void visuBlocsPos(S_liste blocs[NBRE_BLOC]){
    char i = 0;
    for(i=0; i<NBRE_BLOC; i++){
	visuListePos(blocs[i]);
    }
}




