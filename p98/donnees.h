#ifndef _DONNEES_H_
#define _DONNEES_H_

#include <stdio.h>
#include <stdlib.h>
#include "../shared/liste.h"

typedef struct dataHach dataHach;

struct dataHach{
    liste* lMot;
    char firstMot[50];
    unsigned char tabAnalyseMot[26];
    unsigned int nbreMot;
};

#endif


