#include "nbre.h"

bool nbrePrime(int nbre){
    int i = 0;
    for(i=3; i*i<=nbre; i = i+2){
	if(nbre%i == 0){
	    return false;
	}
    }
    return true;
}

void remplissageTabPrime(int tab[], int limite, int taille_tab, int puis){
    int i = 0, j = 1;
    //printf("remplissage pour %d\n", puis);
    tab[0] = pow(2, puis);
    //printf("2^%d => %d, ", puis, tab[0]);
    for(i=3; i<=limite & j<taille_tab; i+=2){
	if(nbrePrime(i)){
	    tab[j] = pow(i, puis);
	    //printf("%d^%d => %d, ", i, puis, tab[j]);
	    j++;
	}
    }
    //printf("\n");
}

int nbreNbrePrime(int limite){
    int i =0, compt = 1;
    for(i=3; i<=limite; i+=2){
	if(nbrePrime(i)){
	    compt++;
	}
    }
    return compt;
}

void aff_tab_struct_lim(elem tab[], int taille_tab, int lim, char *name_tab){
    printf("%s : \n", name_tab);
    int i = 0;
    for(i=0; i<taille_tab-1 && i<lim; i++){
	printf("(%d, %d, %d, %d)", tab[i].val_cour, tab[i].tab_quatre, tab[i].tab_cube, tab[i].pos_tab_carre);
    }
    printf("(%d, %d, %d, %d)\n", tab[i].val_cour, tab[i].tab_quatre, tab[i].tab_cube, tab[i].pos_tab_carre);
    //printf("%d\n", tab[i].val_cour);
}
void aff_tab_struct(elem tab[], int taille_tab, char *name_tab){
    printf("%s : \n", name_tab);
    int i = 0;
    for(i=0; i<taille_tab-1; i++){
	printf("(%d, %d, %d, %d)", tab[i].val_cour, tab[i].tab_quatre, tab[i].tab_cube, tab[i].pos_tab_carre);
    }
    printf("(%d, %d, %d, %d)\n", tab[i].val_cour, tab[i].tab_quatre, tab[i].tab_cube, tab[i].pos_tab_carre);
    //printf("%d\n", tab[i].val_cour);
}

void aff_tab(int tab[], int taille_tab, char *name_tab){
    printf("%s : \n", name_tab);
    int i = 0;
    for(i=0; i<taille_tab-1; i++){
	printf("%d, ", tab[i]);
    }
    printf("%d\n", tab[i]);
}

void rapport_prime_puis(int tab[], int taille_tab, char* name){
    printf("%s\n", name);
    int i = 0;
    for(i=0; i<taille_tab-1; i++){
	printf("%f\n", ((1.0*tab[i])/tab[i+1]));
    }
}

void remplissageTabPrimePrime(int tab[], int limite, int taille_tab){
    int i = 0, j = 1;
    tab[0] = 2;
    for(i=3; i<=limite & j<taille_tab; i+=2){
	if(nbrePrime(i)){
	    tab[j] = i;
	    j++;
	}
    }
    //printf("fin remplissage de %d, j : %d, i : %d\n", puis, j, i);
}

void echange(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void echange_struct(elem *a, elem *b){
    elem tmp = *a;
    *a = *b;
    *b = tmp;
}

bool add_val(int tab[], int taille_ac, int val){
    int i = taille_ac-1;
    while(val < tab[i]){
	//printf("echange entre tab[i+1] : %d et tab[i] : %d, i : %d\n", tab[i+1], tab[i], i);
	echange(&tab[i+1], &tab[i]);
	i--;
    }
    if(val == tab[i]){
	i++;
	while(i<taille_ac){
	    tab[i] = tab[i+1];
	    i++;
	}
	tab[i] = 0;
	return false;
    }
    else{
	tab[i+1] = val;
	return true;
    }
}

void init_tab(int tab[], int taille){
    int i = 0;
    for(i=0; i<taille; i++){
	tab[i] = 0;
    }
}

void init_tab_indice(int tab[NBRE_QUATRE][NBRE_CUBE], int taille1, int taille2){
    int i =0, j = 0;
    for(i=0; i<taille1; i++){
	for(j=0; j<taille2; j++){
	    tab[i][j] = 0;
	}
    }
}

void init_tab_val(elem tab[NBRE_QUATRE*NBRE_CUBE], int tab_carre_0, int tab_cube[], int taille_cube, int tab_quatre[], int taille_quatre){
    int i = 0, j = 0, pos;
    for(i=0; i<taille_quatre; i++){
	for(j=0; j<taille_cube; j++){
	    //printf("i : %d => tab_quatre[i] : %d, j : %d => tab_cube[j] : %d, tab_carre_0 : %d ==> calcul : %d\n", i, tab_quatre[i], j, tab_cube[j], tab_carre_0, tab_quatre[i]+tab_cube[j]+tab_carre_0);
	    pos = i*taille_cube+j;
	    tab[pos].val_interm = tab_quatre[i]+tab_cube[j];
	    tab[pos].val_cour = tab[pos].val_interm+tab_carre_0;
	    tab[pos].pos_tab_carre = 0;
	    tab[pos].tab_quatre = i;
	    tab[pos].tab_cube = j;
	}
    }
}

void tri_fusion(int tab[], int min, int taille){
    if(taille >1){
	tri_fusion(tab, 0, taille/2);
	tri_fusion(tab, taille/2+1, taille);
    }
    printf("apres division\n");
    fusion(tab, min, 2*taille);
}

void fusion(int tab[], int min, int taille){
    int i = 0, j = 0;
    int indice_val_ac = taille/2;
    printf("fusion avec min : %d et taille : %d\n", min, taille);
    aff_tab(tab+min, taille, "tab courant");
    while(indice_val_ac<taille & i>=min){
	i = indice_val_ac -1+min;
	while(tab[j]<tab[i]){
	    echange(&tab[i+1], &tab[i]);
	    i--;
	}
	indice_val_ac++;
    }
}

void tri_insertion(elem tab[], int taille){
    int indice_val_ac = 1;
    int i = 0;
    while(indice_val_ac<taille){
	i = indice_val_ac-1;
	while(tab[i].val_cour<tab[i-1].val_cour){
	    echange_struct(&tab[i], &tab[i-1]);
	    i--;
	}
	indice_val_ac++;
    }
}


