#ifndef _DONNEES_H_
#define _DONNEES_H_

#include <stdio.h>
#include <stdbool.h>

#define NBRE_DIGIT 10
#define NBRE_TRIPLETS 5

typedef struct triplet triplet;
struct triplet{
    int *tab[3];
};

void initTriplets(triplet *t, int *tab);
void affTriplets(triplet *t);
void affTriplet(triplet t);
bool solPossible(triplet *t);
int sumTriplet(triplet t);
int lowestExternalNode(triplet *t);
double tripletsToNbre(triplet *t);

#endif
