#include <math.h>

#include "tab.h"
#include "proba.h"

int max(int a, int b);

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int main(void)
{
    int tab1[TAILLE_TAB] = {0}, tab2[TAILLE_TAB] = {0};
    remplissageTab(tab1, NBRE_DES_6, 6);
    remplissageTab(tab2, NBRE_DES_4, 4);
    double proba = sumProba(tab2, tab1)/((double)NBRE_POSS_9_DES*NBRE_POSS_6_DES);

    //printf("proba : %.8lf (prendre l'arrondi a la septieme decimal apres la virgule)\n", proba);
    printf("%.8lf\n", proba);
    return 0;
}

