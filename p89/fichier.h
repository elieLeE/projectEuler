#ifndef _FICHIER_H_
#define _FICHIER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

FILE* ouvFichier(char *name, char *mode);
void fermerFichier(FILE* fichier);
bool nextLigne(FILE* fichier, char grille[MAX]);

#endif
