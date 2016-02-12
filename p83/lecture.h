#ifndef _LECTURE_H_
#define _LECTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

FILE* ouvFichier(char* name);
void fermerFichier(FILE **f);
void lireMatrice(FILE *fichier, unsigned int* matrice[80]);

#endif
