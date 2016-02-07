#ifndef _FICHIER_H_
#define _FICHIER_H_

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

FILE* ouvFichier(char *name);
void fermetureFichier(FILE** f);
void lectureFichier(FILE*f, triangle tabTri[]); 

#endif
