#include "nbre.h"
#include "tab.h"

#define TAILLE_TAB 1000000

void init_tab(int tab[]){
    int i = 0;
    for(i=0; i<TAILLE_TAB2; i++){
	tab[i] = -1;
    }
}

void reinit_tab(bool tab[]){
    int i = 0;
    for(i=0; i<TAILLE_TAB; i++){
	tab[i] = false;
    }
}

int main(){
    int compt = 0;
    int i =1, j = 0;
    int n_actuelle = 0, n_min = 0;
    bool tab_verif[TAILLE_TAB];
    int tab2[TAILLE_TAB2];
    int long_max = 0, long_actuelle = 0;
    reinit_tab(tab_verif);
    bool boucle = false;

    while(compt < 1000000){
	n_actuelle = i;
	long_actuelle = 0;
	init_tab(tab2);
	j = 0;
	boucle = false;

	while(n_actuelle > 1 & n_actuelle <= 1000000){
	    compt++;
	    tab2[j] = n_actuelle;
	    j++;
	    if(tab_verif[n_actuelle]){
		boucle = true;
		break;
	    }
	    tab_verif[n_actuelle] = true;
	    n_actuelle = sum_diviseurs(n_actuelle);
	    long_actuelle++;
	}
	if(boucle & long_actuelle > 1){
	    long_actuelle = recherche_boucle(tab2, j);
	    if(long_actuelle > long_max){
		long_max = long_actuelle;
		n_min = recherche_min_tab(tab2, (j - long_actuelle), j);
	    }
	}
	i++;
    }

    printf("long_max : %d, min de la chaine : %d\n", long_max, n_min);

    return 0;
}
