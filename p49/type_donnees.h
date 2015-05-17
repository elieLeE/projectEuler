#ifndef _TYPE_DONNEES_H_
#define _TYPE_DONNEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMITE_TAB 37
#define FIRST_NBRE 1001
#define LAST_NBRE 10000
#define NBRE_PERM 3 

typedef struct l_perm *l_perm;
typedef struct l_tabhach *l_tabhach;

struct l_tabhach{
    char *tab;
    char nbre_perm;
    struct l_perm *perm;
    struct l_tabhach *suiv;
};

struct l_perm{
    int nbre;
    struct l_perm *suiv;
};

#endif
