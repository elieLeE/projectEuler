#ifndef _NBRE_H_
#define _NBRE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 50000000
#define LIMITE_CARRE (int)(sqrt(MAX -2*2*2 - 2*2*2*2))
#define LIMITE_CUBE (int)(pow((MAX -2*2- 2*2*2*2), (1.0/3.0)))
#define LIMITE_QUATRE (int)(pow((MAX-2*2- 2*2*2), (1.0/4.0)))

#define NBRE_CARRE nbreNbrePrime(LIMITE_CARRE)
#define NBRE_CUBE nbreNbrePrime(LIMITE_CUBE)
#define NBRE_QUATRE nbreNbrePrime(LIMITE_QUATRE)

typedef struct elem elem;
struct elem{
    int val_cour;
    int val_interm;
    short pos_tab_carre;
    short tab_cube, tab_quatre;
};

void init_tab_indice(int tab[NBRE_QUATRE][NBRE_CUBE], int taille1, int taille2);
void init_tab_val(elem tab[NBRE_QUATRE*NBRE_CUBE], int tab_carre_0, int tab_cube[], int taille_cube, int tab_quatre[], int taille_quatre);
void echange(int *a, int *b);
void echange_struct(elem *a, elem *b);
bool add_val(int tab[], int taille_ac, int val);
void rapport_prime_puis(int tab[], int taille_tab, char* name);
void aff_tab(int tab[], int, char*); 
void aff_tab_struct(elem tab[], int, char*); 
void remplissageTabPrime(int tab[], int, int, int);
int nbreNbrePrime(int );
bool nbrePrime(int nbre);
void remplissageTabPrimePrime(int tab_prime[], int, int);
void fusion(int tab[], int, int taille);
void tri_fusion(int tab[], int min, int taille);

#endif
