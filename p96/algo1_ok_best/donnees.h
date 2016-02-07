#ifndef _DONNEES_H_
#define _DONNEES_H_

#define NBRE_LIGNE 9
#define NBRE_COL 9
#define NBRE_VAL_POSS 9

typedef struct S_elem S_elem;
typedef struct S_tab S_tab;

struct S_elem{
    char *val;
    char nbreElemImp;
    char posValPoss;
    char valPoss[9];
    char** elemImp;	//pour realloc => deux **
};

struct S_tab{
    char nbreElem;
    S_elem* elems;
};
#endif
