#ifndef _TABHACH_H_
#define _TABHACH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "type_donnees.h"

c_tabhach creerTabHach();
bool tabHachEmpty(c_tabhach t);
void visuTabHach(l_tabhach tab[100], char *name);
void initTabHach(l_tabhach tab[100]);
void visuElemTabHach(c_tabhach l, char pos);
void ajoutElemTabHach(l_tabhach *l, char right_partie);

#endif
