#include "tabhach.h"

void initTabHach(l_tabhach tab[100]){
    char i = 0;
    for(i=0; i<100; i++){
	tab[i].deb = creerTabHach();
	tab[i].end = tab[i].deb;
    }
}

c_tabhach creerTabHach(){
    return NULL;
}

bool tabHachEmpty(c_tabhach t){
    return t == NULL;
}

void visuTabHach(l_tabhach tab[100], char *name){
    char i = 0;
    printf("%s\n", name);
    for(i=0; i<100; i++){
	visuElemTabHach(tab[i].deb, i);
    }
    printf("\n");
}

void visuElemTabHach(c_tabhach l, char pos){
    c_tabhach p = l;
    while(!tabHachEmpty(p)){
	printf("(%d, %d) ", p->right, pos);
	p = p->suiv;
    }
}

void ajoutElemTabHach(l_tabhach *l, char right_partie){
    c_tabhach nouv = (c_tabhach )calloc(1, sizeof(struct c_tabhach));
    nouv->right = right_partie;
    nouv->suiv = NULL;
    if(tabHachEmpty(l->deb)){
	l->deb = nouv;
	l->end = nouv;
    }
    else{
	l->end->suiv = nouv;
	l->end = l->end->suiv;
    }
}
    
