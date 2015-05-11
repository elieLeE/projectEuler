#ifndef _LISTE_H_
#define _Liste_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type_donnees.h"

void ajoutElemEnQueue(l_elem l, char right, char left);
void remplissageListeNbrePentagonal(l_elem *l);
bool isEmpty(c_elem l);
void ajoutElem(l_elem *l, char right, char left);
c_elem creerListe();
void visuListe(c_elem l, char *name);

#endif
