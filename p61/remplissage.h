#ifndef _REMPLISSAGE_H_
#define _REMPLISSAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type_donnees.h"
#include "liste.h"
#include "tabhach.h"

void remplissageListeNbreOctagonal(l_elem *l);
void remplissage(l_elem *l, l_tabhach tabhach[5][100]);
void remplissageNbre(l_tabhach tabhach[100], int dist_init, int a_dist);

#endif
