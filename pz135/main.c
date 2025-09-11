#include <stdio.h>
#include <stdlib.h>
#define TAILLE_TAB 2000

void initTabCarre(long long tab[]){
    long long i = 0;
    for(i=0; i<TAILLE_TAB; i++){
        tab[i] = i*i;
    }
}

void affTab(long long tab[]){
    int i = 0;
    for(i=0; i<TAILLE_TAB; i++){
        printf("tab[%d] : %lld\n", i, tab[i]);
    }
}

int compt(int tab[]){
    int i = 0, compt = 0;
    for(i=0; i<TAILLE_TAB; i++){
        if(tab[i] == 10){
            compt++;
        }
    }
    return compt;
}

int searchDicho(long long tab[], long long val){
    int i = TAILLE_TAB/2;

    return 0;
}

int main(void){
    long long *tabCarre = malloc(TAILLE_TAB*sizeof(long long));
    int *tabVal = calloc(TAILLE_TAB, sizeof(int));
    int ecart, i, j, k;
    long long sum;

    initTabCarre(tabCarre);
    //affTab(tabCarre);

    for(i=TAILLE_TAB-1; i>=0; i--){
        printf("i : %d\n", i);
        ecart = 1;
        j = i-ecart;
        k = j - ecart;
        while(k>=0){
            sum = tabCarre[i] - tabCarre[j] - tabCarre[k];
            printf("%d -%d - %d : %lld\n", i, j, k, sum);
            //getchar();
            if(sum>=TAILLE_TAB){
                break;
            }
            else if(sum>=0){
                tabVal[sum]++;
            }
            ecart++;
            j = i-ecart;
            k = j - ecart;
        }
    }

    /*for(i=0; i<TAILLE_TAB; i++){
        printf("tab[%d] : %d\n", i, tabVal[i]);
    }*/

    printf("nbre de valeurs : %d\n", compt(tabVal));

    return 0;
}


