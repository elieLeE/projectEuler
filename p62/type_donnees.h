#ifndef _TYPE_DONNEES_H_
#define _TYPE_DONNEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMITE_TAB 100
#define LIMITE_SEARCH 10000
#define NBRE_PERM 5 

typedef struct l_perm *l_perm;
typedef struct l_tabhach *l_tabhach;

struct l_tabhach{
    char *tab;
    char nbre_perm;
    struct l_perm *perm;
    struct l_tabhach *suiv;
};

struct l_perm{
    long nbre;
    struct l_perm *suiv;
};

#endif
