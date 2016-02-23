#include "tab.h"

void setTab(unsigned int *tab, char* mot, unsigned long n){
    unsigned int taille = strlen(mot);
    unsigned int i = taille-1;
    unsigned long n2;
    while(n>=1){
	n2 = n/10;
	tab[mot[i]-65] = (n - n2*10);
	n = n/10;
	i--;
    }
}

void initTab(unsigned int *tab){
    unsigned int i;
    for(i=0; i<26; i++){
	tab[i] = 0;
    }
}

void visuTab2(unsigned int* tab){
    unsigned int i;
    for(i=0; i<26; i++){
	printf("%d, ", tab[i]);
    }
    printf("\n");
}

void visuTab(unsigned int* tab, char* mot){
    int i;
    int taille = strlen(mot);
    for(i=0; i<taille; i++){
	printf("%d, ", tab[(unsigned char)(mot[i]-65)]);
    }
    printf("\b\b \n");
}

bool nextCombi(unsigned int *tab, char* mot){
    int taille = strlen(mot);
    int i, j;
    do{
	i = taille-1;
	while((i>=0) && (tab[(unsigned char)(mot[i]-65)] == 1)){
	    i--;
	}
	//printf("i : %d, tab[mot[8]-65] : %d\n", i, tab[(unsigned char)(mot[8]-65)]);
	if(i<0){
	    return false;
	}
	tab[(unsigned char)(mot[i]-65)]--;
	for(j=i+1; j<taille; j++){
	    tab[(unsigned char)(mot[j]-65)] = 9;
	}
	visuTab(tab, mot);
	//printf("%s => %ld\n", mot, valMot(mot, tab));
	//getchar();
    }while(!verifTab(tab, mot));
    visuTab(tab, mot);
    getchar();
    return true;
}

bool verifTab(unsigned int *tab, char * mot){
    unsigned int i, taille = strlen(mot), ind;
    bool tabBool[9] = {false};
    for(i=0; i<taille; i++){
	ind = (unsigned char)(mot[i]-65);
	if(((tab[ind] == 0) || (tabBool[tab[ind]]))){
	    return false;
	}
	tabBool[tab[ind]] = true;
    }
    return true;
}

char** affectationMot(dataHach *d){
    unsigned int i;
    liste* p;
    char** s = my_calloc((d->nbreMot)*sizeof(char*));
    p = d->lMot;
    s[0] = d->firstMot;
    for(i=1; i<(d->nbreMot); i++){
	s[i] = (char *)(p->data);
	p = p->suiv;
    }
    return s;
}


