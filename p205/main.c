#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define NBRE_DES_4 9
#define NBRE_DES_6 6
#if NBRE_DES_4*4 > NBRE_DES_6*6
#define TAILLE_TAB NBRE_DES_4*4 + 1
#else
#define TAILLE_TAB NBRE_DES_6*6 + 1
#endif
//#define TAILLE_TAB max(NBRE_DES_4*4,  NBRE_DES_6*2)
#define NBRE_POSS_9_DES (double)(pow(4, NBRE_DES_4))
#define NBRE_POSS_6_DES (double)(pow(6, NBRE_DES_6))

int max(int a, int b);
void remplissageTab(int tab[], int nbreDes, int);
void affTab(char*, int des[], int nbredes);
void initDes(int des[], int nbredes);
bool nextConfig(int tab[], int nbreDes, int);
double sumProba(int tab1[], int tab2[]);

int max(int a, int b){
    if(a > b){
	return a;
    }
    return b;
}

void remplissageTab(int tab[], int nbreDes, int max){
    int *des = (int*)calloc(nbreDes, sizeof(int));
    initDes(des, nbreDes);
    while(true){
	if(!nextConfig(des, nbreDes, max)){
            break;
        }
        else{
            tab[sumTab(des, nbreDes)]++;
        }
    }
    free(des);
}

int sumTab(int tab[], int nbreDes){
    int i =0, sum =0 ;
    for(i=0; i<nbreDes; i++){
        sum += tab[i];
    }
    return sum;
}

bool nextConfig(int tab[], int nbreDes, int max){
    int i = nbreDes-1;
    while(i>=0 && tab[i] == max){
        i--;
    }
    if(i <0){
        return false;
    }
    tab[i]++;
    if(i<nbreDes-1){
        int j = 0;
        for(j=i+1; j<nbreDes; j++){
            tab[j] = 1;
        }
    }
    return true;
}

void affTab(char *name, int tab[], int taille){
    int i = 0;
    printf("%s : \n", name);
    for(i=0; i<taille; i++){
        printf("tab[%d] : %d\n", i, tab[i]);
    }
    printf("\n\n");
}

void initDes(int des[], int nbreDes){
    int i = 0;
    for(i=0; i<nbreDes; i++){
        des[i] = 1;
    }
    des[nbreDes-1] = 0;
}

double sumProba(int tab1[], int tab2[]){
    double sumTot = 0.0, sumInt;
    int i = 0, j = 0;
    for(i=0; i<TAILLE_TAB; i++){
	if(tab1[i] != 0){
	    sumInt = sumTab(tab2, i);
	    sumTot += sumInt*tab1[i];
	}
    }
    return sumTot;
}

int main(void)
{
    int tab1[TAILLE_TAB] = {0}, tab2[TAILLE_TAB] = {0};
    remplissageTab(tab1, NBRE_DES_6, 6);
    remplissageTab(tab2, NBRE_DES_4, 4);
    double proba = sumProba(tab2, tab1)/((double)NBRE_POSS_9_DES*NBRE_POSS_6_DES);

    printf("proba : %.8lf (prendre l'arrondi a la septieme decimal apres la virgule)\n", proba);
    return 0;
}

