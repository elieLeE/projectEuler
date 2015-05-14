#ifndef _TABHACH_H_
#define _TABHACH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type_donnees.h"

bool tabHachEmpty(l_tabhach t);
void visuTabHach(l_tabhach tab[100], char *name);
void initTabHach(l_tabhach tab[100]);
void ajoutElemTabHach(l_tabhach *l, long nbre, char* tab);
void visuL(l_tabhach l);

#endif
