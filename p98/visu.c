#include "visu.h"

void visuTabHach(liste*** tabH, unsigned int tL, unsigned int tC){
    unsigned int i, j;
    for(i=0; i<tL; i++){
	for(j=0; j<tC; j++){
	    visuListe(tabH[i][j], (void(*)(void*))visuCouple, "");
	    /*if(!listeEmpty(tabH[i][j])){
		printf("\n");
	    }*/
	}
    }
}

void visuCouple(void* data){
    dataHach* d = (dataHach*)data;
    if(d->nbreMot > 1){
	printf("%s, ", d->firstMot);
	visuListe(d->lMot, (void(*)(void *))visuWord, "\b\b \n");
    }
}

void visuWord(void *data){
    printf("%s, ", ((char*)data));
}

void visuOK(liste*** l, unsigned int tL, unsigned int tC){
    unsigned int i, j;
    liste *p1, *p2;
    bool b1;
    for(i=0; i<tL; i++){
	//printf("long %d => \n", i);
	for(j=0; j<tC; j++){
	    //printf("\tsumMot %d => \n", j);
	    p1 = l[i][j];
	    b1 = false;
	    while(!listeEmpty(p1)){
		b1 = true;
		dataHach* d = (dataHach*)p1->data;
		p2 = d->lMot;
		if(egaliteMot(d->firstMot, "RACE")){
		    getchar();
		}
		printf("\t\t%s (%d), ", d->firstMot, sumAsciiMot(d->firstMot));
		while(!listeEmpty(p2)){
		    char *d2 = (char *)p2->data;
		    if(egaliteMot(d2, "RACE")){
			getchar();
		    }
		    printf("%s (%d), ", d2, sumAsciiMot(d2));
		    p2 = p2->suiv;
		}
		printf("\n");
		p1 = p1->suiv;
	    }
	    if(b1){
		printf("\n\n");
	    }
	}
    }
}
