#ifndef _TABHACH_H_
#define _TABHACH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type_donnees.h"
#include "liste.h"
#include "../shared/alloc.h"

bool tabHachEmpty(l_tabhach t);
void visuTabHach(l_tabhach tab[LIMITE_TAB]);
void initTabHach(l_tabhach tab[LIMITE_TAB]);
void ajoutElemTabHach(l_tabhach *l, int nbre, char* tab);
void visuL(l_tabhach l);

#endif
