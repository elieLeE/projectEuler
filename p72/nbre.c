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

/*int phi(int nbre, int tab[], int taille_tab){
    static double tab_phi[1000000];
    static int tab_pos = 0;
    int i=0, debut = 0;
    double produit = 1.0;
    double tmp;
    int result_div_debut, indice_div_debut;
    if(nbre == tab[tab_pos]){
	tab_pos++;
	tab_phi[nbre-2] = (1.0*nbre-1)/nbre;
	return (nbre-1);
    }
    else{
	if(indiceFirstDiviseur(nbre, &debut, tab)){
	    //printf("premier diviseur : %d\n", tab[debut]);
	    //tmp = (1.0*(tab[debut]-1))/(tab[debut]);
	    //printf("debut  : %d, tab[debut] : %d, nbre/tab[debut]-2 = %d, tab_phi[nbre/tab[debut]-2) : %f\n", debut, tab[debut], (int)(nbre/tab[debut]-2), tab_phi[nbre/tab[debut]-2]);
	    result_div_debut = nbre/tab[debut];
	    indice_div_debut = result_div_debut-2;
	    produit = tab_phi[indice_div_debut];
	    if(tab[debut] != result_div_debut){
		if(!(result_div_debut%2) == 0 || result_div_debut == 2){
		    if(nbrePrime(result_div_debut)){	//A changer par une recherche dichotomique dans le tableau de nbre permier
			produit *= (1.0*result_div_debut-1)/(result_div_debut);
			//printf("%d premier\n", result_div_debut);
		    }
		}
	    }
	    /*printf("produit : %f\n", produit);
	      printf("debut : %d, div_debut : %d, indice_div_debut : %d, result_div_debut : %d, produit : %f\n", debut, div_debut, indice_div_debut, result_div_debut, produit);
	}
	//printf("div_debut = %d, result_div_debut : %d\n", div_debut, result_div_debut);
	for(i=tab[debut]+1; tab[i]<result_div_debut && i<taille_tab; i++){
	    //printf("tab[%d] : %d => ", i, tab[i]);
	    if(nbre%tab[i] == 0){
		//printf("ici\n");
		tmp = ((tab[i]-1)*1.0)/(tab[i]);
		produit = produit*tmp;
	    }
	}
    }
    tab_phi[nbre-2] = produit;
    /*printf("tab_phi : ");
      aff_tab(tab_phi, taille_tab);
    return (int)(produit*nbre);
}*/

bool indiceFirstDiviseur(int nbre, int *indice, int tab[]){
    int i = 0;
    while(tab[i] <= nbre){
	if(nbre%tab[i] == 0){
	    *indice = i;
	    return true;
	}
	i++;
    }
    return false;
}

void remplissageTabPrime(int tab[], int limite, int taille_tab){
    int i = 0, j = 1;
    tab[0] = 2;
    for(i=3; i<=limite && j<taille_tab; i+=2){
	if(nbrePrime(i)){
	    tab[j] = i;
	    j++;
	}
    }
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

void aff_tab(double tab[], int taille_tab){
    int i =0;
    for(i=0; i<taille_tab-1; i++){
	printf("%f, ", tab[i]);
    }
    printf("%f\n", tab[i]);
}


bool nbrePrimeTab(int n, int generateur, int tab[]){
    int i = 0;
    for(i=0; tab[i]<n; i++){
	if(i!=generateur){
	    if(n%tab[i] == 0){
		return false;
	    }
	}
    }
    return true;
}

int phi2(int limite, int mul, int tab_prime[]){
    int i=mul, j = 0, j_s=0;
    int compt = mul-1;
    int compt_tmp = 0;
    double phi = 1.0;
    bool deja_fait = false;
    for(i=mul+mul; i<=limite; i+=mul){
	compt_tmp = 1;
	deja_fait = false;
	printf("pour %d (1 pris d'office)\n", i);
	if(!nbrePrimeTab(i, mul, tab_prime)){
	   for(j=j_s; tab_prime[j]*mul<limite;j++){
	       if((tab_prime[j]!=mul && i%tab_prime[j]==0)){
		   printf("j : %d => on ne prends pas\n", tab_prime[j]);
		   break;
	       }
	       else{
		   compt_tmp++;
	       }
	   }
	   if(deja_fait){
	       printf("i : %d => on ne prends pas\n", i);
	   }
	   else{
	       printf("i : %d => on prends a hauteur de %d\n", i, compt_tmp);
	       compt+=compt_tmp;
	   }
	}
	printf("pour %d => phi : %d\n", i, compt_tmp);
	compt+=compt_tmp;
    }
    return compt;
}







