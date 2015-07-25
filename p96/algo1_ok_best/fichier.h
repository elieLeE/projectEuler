#ifndef _FICHIER_H_
#define _FICHIER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "donnees.h"


FILE* ouvFichier(char *name, char *mode);
void fermerFichier(FILE* fichier);
void lectureGrille(FILE* fichier, char **grille);

#endif
