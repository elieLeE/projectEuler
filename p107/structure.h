#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define NBRE_SOMMETS 40
//#define NBRE_SOMMETS 

typedef struct arete arete;
typedef struct sommet sommet;

struct arete{
    unsigned char n1, n2;
    int val;
    bool etat;
};

struct sommet{
    int nbreCoInit, nbreCoRest, num;
    int *indSomCo;
    arete **tabArete;
};

void* my_malloc(int);
arete* allocArete(int taille);
void initTabSommets(sommet tabS[], int maxCo);
void remplissageTabSommets(sommet tabSommet[], arete tabArete[], int);

void affSommet(sommet const s);
void affTabSommet(sommet const tabS[]);
void affTabSommetCo(int const tab[], int const taille);
void affTabArete(arete const tabArete[], int);
void affArete(arete const a, char *, char*);
void affTabSomArete(arete *tabArete[], int const taille);
char transfoNomSommet(int n);

void liberationSom(sommet s);
void libTabSommets(sommet tabSommet[]);


#endif
