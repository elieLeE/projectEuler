#ifndef _LISTE_H_
#define _Liste_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type_donnees.h"
#include "../shared/alloc.h"

bool isSol(l_perm p, int tab[3]);
bool isEmpty(l_perm l);
void ajoutElem(l_perm *l, long nbre);
l_perm creerListe();
void visuListePerm(l_perm l);
long searchMin(l_perm l);

#endif
