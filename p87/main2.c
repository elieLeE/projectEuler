#include "nbre.h"
#include <math.h>
#include <string.h>


//2 nombreds peuvent eventuellement etre obtenues avec deux triplets differents => compteur incorrecte
//non fonctionnel mais plus rapide que main1.c => malgre tout pas assez rapide

int main(){
    int last_val = 0, i = 0, j = 0, compt = 0, compt_tab = 0, nbre_elem, compt_aff = 0;
    elem tmp;
    printf("MAX : %d, racine carre de %d = %d : %d, racine cubique de %d = %d : %d, racine quatrieme de %d = %d : %d\n", MAX, MAX, (MAX), LIMITE_CARRE, MAX, (MAX), LIMITE_CUBE, MAX, (MAX), LIMITE_QUATRE);
    printf("nbre de nbre permier inferieur a %d : %d\n", LIMITE_CARRE, nbreNbrePrime(LIMITE_CARRE));
    printf("nbre de nbre permier inferieur a %d : %d\n", LIMITE_CUBE, nbreNbrePrime(LIMITE_CUBE));
    printf("nbre de nbre permier inferieur a %d : %d\n", LIMITE_QUATRE, nbreNbrePrime(LIMITE_QUATRE));

    printf("NBRE_CARRE : %d, NBRE_CUBE : %d, NBRE_QUATRE : %d\n", NBRE_CARRE, NBRE_CUBE, NBRE_QUATRE);


    elem tab_val[NBRE_QUATRE*NBRE_CUBE];
    int tab_carre[NBRE_CARRE];
    int tab_cube[NBRE_CUBE];
    int tab_quatre[NBRE_QUATRE];

    remplissageTabPrime(tab_carre, LIMITE_CARRE, NBRE_CARRE, 2); 
    remplissageTabPrime(tab_cube, LIMITE_CUBE, NBRE_CUBE, 3);
    remplissageTabPrime(tab_quatre, LIMITE_QUATRE, NBRE_QUATRE, 4);
    init_tab_val(tab_val, tab_carre[0], tab_cube, NBRE_CUBE, tab_quatre, NBRE_QUATRE);
    //tri_fusion(tab_val, 0, NBRE_QUATRE*NBRE_CUBE);
    tri_insertion(tab_val, NBRE_QUATRE*NBRE_CUBE);
    //aff_tab_struct(tab_val, NBRE_CUBE*NBRE_QUATRE, "tab_val");

    last_val = 0;
    nbre_elem = NBRE_QUATRE*NBRE_CUBE;
    while(compt_tab != NBRE_QUATRE*NBRE_CUBE){
	//printf("compt_tab : %d\n", compt_tab);
	//printf("last_val : %d, tab_val[0].val_cour : %d\n", last_val, tab_val[0].val_cour);
	if(compt_aff == 10000){
	    printf("triplet (%d, %d, %d, %d), compt_tab : %d, compt : %d\n", tab_val[0].val_cour, tab_val[0].tab_quatre, tab_val[0].tab_cube, tab_val[0].pos_tab_carre, compt_tab, compt);
	    compt_aff = 0;
	}
	compt_aff++;
	//aff_tab_struct_lim(tab_val, NBRE_CUBE*NBRE_QUATRE, 10, "tab_val");
	if(tab_val[0].val_cour != last_val){
	    compt++;
	    last_val = tab_val[0].val_cour;
	    //printf("compt++, triplets : (%d, %d, %d)\n", tab_carre[tab_val[0].pos_tab_carre], tab_cube[tab_val[0].tab_cube], tab_quatre[tab_val[0].tab_quatre]);
	}
	tab_val[0].pos_tab_carre++;
	//printf("tab_val[0].tab_quatre : %d, tab_val[0].tab_cube : %d, pos_tab_carre : %d\n", tab_val[0].tab_quatre, tab_val[0].tab_cube, tab_val[0].pos_tab_carre);
	if(tab_val[0].pos_tab_carre < NBRE_CARRE){
	    tab_val[0].val_cour = tab_val[0].val_interm + tab_carre[tab_val[0].pos_tab_carre];
	    //printf("tab_val[0].val_cour : %d => ", tab_val[0].val_cour);
	    if(tab_val[0].val_cour > MAX){
		//printf("valeur trop grande\n");
		nbre_elem--;
		compt_tab++;
		i = 0;
		tmp = tab_val[0];
		while(i<nbre_elem){
		    tab_val[i] = tab_val[i+1];
		    i++;
		}
		//memcpy(tab_val, tab_val+1, nbre_elem*sizeof(struct elem));
		tab_val[i] = tmp;
		compt_tab++;
	    }
	    else{
		//printf("ajustement tableau\n");
		i = 0;
		while(tab_val[i].val_cour > tab_val[i+1].val_cour & i<nbre_elem-1){
		    //printf("i : %d, tb_val[i].val_cour : %d, tab_val[i+1].val_cour : %d\n", i, tab_val[i].val_cour, tab_val[i+1].val_cour);
		    echange_struct(&tab_val[i], &tab_val[i+1]);
		    i++;
		}
	    }
	}
	else{
	    //printf("changement tableau, tab_val[0] : %d expedié en fin de tableau\n", tab_val[0].val_cour);
	    nbre_elem--;
	    i = 0;
	    tmp = tab_val[0];
	    while(i<nbre_elem){
		tab_val[i] = tab_val[i+1];
		i++;
	    }
	    //memcpy(tab_val, tab_val+1, nbre_elem*sizeof(struct elem));
	    tab_val[i] = tmp;
	    compt_tab++;
	}
	//printf("\n");
    }

    if(MAX == 50000000){
	printf("compt : %d, compt -1097343 : %d\n", compt, (compt -1097343));
    }
    else{
	printf("compt : %d\n", compt);
    }


    return 0;
}
