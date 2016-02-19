#ifndef _TABHACH_H_
#define _TABHACH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type_donnees.h"
#include "liste.h"

bool tabHachEmpty(l_tabhach t);
void visuTabHach(l_tabhach tab[LIMITE_TAB]);
void initTabHach(l_tabhach tab[LIMITE_TAB]);
l_tabhach ajoutElemTabHach(l_tabhach *l, long nbre, char* tab);
void visuL(l_tabhach l);

#endif
