#ifndef _TAB_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "liste.h"
#include "tabhach.h"

void remplissageTabHachNbreTriangulaire(l_tabhach tab[100]);
void remplissageTabHachNbreCarre(l_tabhach tab[100]);
void remplissageTabHachNbrePentagonal(l_tabhach tab[100]);
void remplissageTabHachNbreHexagonal(l_tabhach tab[100]);
void remplissageTabOctagonal(bool tab[100][100]);

void afftabNbre(bool tab[100][100], char *name);
void firstNbre(bool tab[100][100], int *left, int *right, int *dist);
void remplissageTabCarre(bool tab[100][100]);
void remplissageTabTriangulaire(bool tab[100][100]);
void remplissageTabPentagonal(bool tab[100][100]);

#endif
