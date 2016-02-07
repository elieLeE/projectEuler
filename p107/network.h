#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int poidsNetwork(arete tab[], int);
void affSomDone(bool tab[]);
bool areteSupprimable(sommet tabSommet[], arete a);
bool otherPathFound(sommet s, int somCible);
bool searchOtherPath(sommet s[], int, bool somDone[], int sommetCible);
bool otherPath(sommet s[], int sommetDepart, int sommetCible);
void reductionNetwork(arete tabArete[], sommet tabSommet[], int);

#endif
