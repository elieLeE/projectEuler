#include "nbre.h"
#include <math.h>

#define MAX 50000000
#define LIMITE_CARRE (int)(sqrt(MAX -2*2*2 - 2*2*2*2))
#define LIMITE_CUBE (int)(pow((MAX -2*2- 2*2*2*2), (1.0/3.0)))
#define LIMITE_QUATRE (int)(pow((MAX-2*2- 2*2*2), (1.0/4.0)))

#define NBRE_CARRE nbreNbrePrime(LIMITE_CARRE)
#define NBRE_CUBE nbreNbrePrime(LIMITE_CUBE)
#define NBRE_QUATRE nbreNbrePrime(LIMITE_QUATRE)

//2 nombreds peuvent eventuellement etre obtenues avec deux triplets differents => compteur incorrecte
//fonctionnel mais tres long

int main(){
    int i = 0, j = 0, k = 0, compt = 0, sum  = 0, sum_tmp = 0;
    int taille_tmp = 1;

    printf("MAX : %d, racine carre de %d = %d : %d, racine cubique de %d = %d : %d, racine quatrieme de %d = %d : %d\n", MAX, MAX, (MAX), LIMITE_CARRE, MAX, (MAX), LIMITE_CUBE, MAX, (MAX), LIMITE_QUATRE);
    printf("nbre de nbre permier inferieur a %d : %d\n", LIMITE_CARRE, nbreNbrePrime(LIMITE_CARRE));
    printf("nbre de nbre permier inferieur a %d : %d\n", LIMITE_CUBE, nbreNbrePrime(LIMITE_CUBE));
    printf("nbre de nbre permier inferieur a %d : %d\n", LIMITE_QUATRE, nbreNbrePrime(LIMITE_QUATRE));

    printf("NBRE_CARRE : %d, NBRE_CUBE : %d, NBRE_QUATRE : %d\n", NBRE_CARRE, NBRE_CUBE, NBRE_QUATRE);


    int tab_val[NBRE_CARRE*NBRE_CUBE*NBRE_QUATRE]; 

    int tab_carre[NBRE_CARRE];
    int tab_cube[NBRE_CUBE];
    int tab_quatre[NBRE_QUATRE];

    remplissageTabPrime(tab_carre, LIMITE_CARRE, NBRE_CARRE, 2); 
    remplissageTabPrime(tab_cube, LIMITE_CUBE, NBRE_CUBE, 3);
    remplissageTabPrime(tab_quatre, LIMITE_QUATRE, NBRE_QUATRE, 4);
    tab_val[0] = tab_carre[0]+tab_cube[0]+tab_quatre[0];



    printf("compt : %d\n", compt);
    for(i=0; i<NBRE_QUATRE; i++){
	for(j=0; j<NBRE_CUBE; j++){
	    printf("i : %d, j : %d\n", i, j);
	    sum = tab_quatre[i] + tab_cube[j]; 
	    for(k=0; k<NBRE_CARRE; k++){
		sum_tmp = sum + tab_carre[k];
		if(sum_tmp <= MAX){
		    if(add_val(tab_val, taille_tmp, sum_tmp)){
			taille_tmp++;
			compt++;
		    }
		}
		else{
		    break;
		}
	    }
	}
    }

    printf("compt : %d\n", compt);


    return 0;
}
