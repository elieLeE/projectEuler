#include "structure.h"

void initTabSommets(sommet tabS[], int maxCo){
    int i =0;
    for(i=0; i<NBRE_SOMMETS; i++){
	tabS[i].nbreCoInit = 0;
	tabS[i].nbreCoRest = 0;
	tabS[i].num = 0;
	/*tabS[i].indSomCo = (int*)my_malloc(maxCo*sizeof(int));
	tabS[i].tabArete = (arete**)my_malloc(maxCo*sizeof(arete*));*/
	tabS[i].indSomCo = (int*)my_calloc(maxCo*sizeof(int));
	tabS[i].tabArete = (arete**)my_calloc(maxCo*sizeof(arete*));
    }
}

void affTabInd(int tabI[]){
    int i = 0;
    for(i=0; i<NBRE_SOMMETS; i++){
	printf("tabI[%d] : %d\n", i, tabI[i]);
    }
}

void remplissageTabSommets(sommet tabSommet[], arete tabArete[], int nbreArete){
    int i = 0;
    int tabInd[NBRE_SOMMETS] = {0};

    for(i=0; i<nbreArete; i++){
        tabSommet[tabArete[i].n1].num = tabArete[i].n1;
        tabSommet[tabArete[i].n1].nbreCoInit++;
        tabSommet[tabArete[i].n1].indSomCo[tabInd[tabArete[i].n1]] = tabArete[i].n2;
        tabSommet[tabArete[i].n1].tabArete[tabInd[tabArete[i].n1]] = &tabArete[i];

        tabSommet[tabArete[i].n2].num = tabArete[i].n2;
        tabSommet[tabArete[i].n2].nbreCoInit++;
        tabSommet[tabArete[i].n2].indSomCo[tabInd[tabArete[i].n2]] = tabArete[i].n1;
        tabSommet[tabArete[i].n2].tabArete[tabInd[tabArete[i].n2]] = &tabArete[i];

        tabInd[tabArete[i].n1]++;
        tabInd[tabArete[i].n2]++;
    }
    for(i=0; i<NBRE_SOMMETS; i++){
        tabSommet[i].nbreCoRest = tabSommet[i].nbreCoInit;
    }
}



void libTabSommets(sommet tabSommet[]){
    int i = 0;
    for(i=0; i<NBRE_SOMMETS; i++){
	liberationSom(tabSommet[i]);
    }
}

void liberationSom(sommet s){
    free(s.indSomCo);
    free(s.tabArete);
}

char transfoNomSommet(int n){
    switch(n){
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'E';
    case 5:
        return 'F';
    case 6:
        return 'G';
    default:
        return'Z';
    }
}

void affArete(arete const a, char *av, char *ap){
    printf("%s => (%d, %d, %d)%s", av, a.n1, a.n2, a.val, ap);
}

void affTabArete(arete const tabArete[], int nbreArete){
    int i = 0;
    printf("nbreArete : %d\n", nbreArete);
    for(i=0; i<nbreArete; i++){
        if(tabArete[i].etat){
	    printf("arete %d => ", i);
            affArete(tabArete[i], "", "\n");
        }

    }
    printf("\n");
}

void affTabSommet(sommet const tabS[]){
    int i = 0;
    for(i=0; i<NBRE_SOMMETS; i++){
        affSommet(tabS[i]);
    }
    printf("\n");
}

void affSommet(sommet const s){
    printf("sommet %d => nbreCoInit : %d, nbreCoRest : %d, sommet Co : ", s.num, s.nbreCoInit, s.nbreCoRest);
    affTabSommetCo(s.indSomCo, s.nbreCoInit);
    affTabSomArete((s.tabArete), s.nbreCoInit);
    printf("\n\n");
}

void affTabSommetCo(int const tab[], int const taille){
    int i = 0;
    for(i=0; i<taille; i++){
        printf("%d, ", tab[i]);
    }
}

void affTabSomArete(arete *tabArete[], int const taille){
    int i = 0;
    printf(" aretes : ");
    for(i=0; i<taille; i++){
        printf("(%d, %d, %d), ", tabArete[i]->n1, tabArete[i]->n2, tabArete[i]->val);
    }
}

