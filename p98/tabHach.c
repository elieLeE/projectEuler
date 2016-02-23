#include "tabHach.h"

void vListe(liste* l){
    printf("vListe => ");
    if(listeEmpty(l)){
	printf("l NULL\n");
    }
    else{
	dataHach* d = l->data;
	printf("%s\n", d->firstMot);
    }
}

void remplissageTabHach(FILE* f, liste*** tabhach){
    char newWord[50];
    unsigned int longMot, sumAscii;
    while(lireMot(f, newWord)){
	longMot = longeurMot(newWord);
	sumAscii = sumAsciiMot(newWord);
	liste *p = searchListe(tabhach[longMot][sumAscii], newWord);
	if(p == NULL){
	    dataHach *d = my_calloc(sizeof(struct dataHach));
	    d->lMot = NULL;
	    memcpy(d->firstMot, newWord, longMot);
	    analyseMot(newWord, d->tabAnalyseMot);
	    d->nbreMot = 1;
	    addElementFirst(&tabhach[longMot][sumAscii], d);
	}
	else{
	    dataHach* d = p->data;
	    d->nbreMot++;
	    char *word = my_calloc(50*sizeof(char));
	    memcpy(word, newWord, longMot);
	    addElementFirst(&(d->lMot), word);
	}
    }
}

liste* searchListe(liste* l, char* mot){
    liste* p = l;
    unsigned char tabAnalyseMot[26] = {0};
    analyseMot(mot, tabAnalyseMot);
    dataHach* d;
    while(!listeEmpty(p)){
	d = p->data;
	if(areAnagramesWords(d->tabAnalyseMot, tabAnalyseMot)){
	    return p;
	}
	p = p->suiv;
    }
    return NULL;
}

void liberationTabHach(liste*** tabH, unsigned int tL, unsigned int tC){
    unsigned int i, j;
    liste *p;
    for(i=0; i<tL; i++){
	for(j=0; j<tC; j++){
	    p = tabH[i][j];
	    while(!listeEmpty(p)){
		dataHach* d = (dataHach*)p->data;
		freeListe(&(d->lMot));
		removeFirstElement(&p);
	    }
	}
    }
    liberationTab2D((void**)tabH, tL);
}

unsigned int maxSquare(liste*** tabH, unsigned int tL, unsigned int tC){
    int i, j;
    unsigned int maxSq = 0;
    dataHach *d;
    liste *p;
    for(i=tL-1; i>=0; i--){
	for(j=tC-1; j>=0; j--){
	    p = tabH[i][j];
	    while(!listeEmpty(p)){
		d = (dataHach*)(p->data);
		if(d->nbreMot > 1){
		    maxSq = max(maxSq, areAnagramSquare(d));
		}
		p = p->suiv;
	    }
	}
    }
    return maxSq;
}

