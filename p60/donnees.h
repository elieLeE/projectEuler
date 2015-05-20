#ifndef _DONNEES_H_
#define _DONNEES_H_

#define LIMITE 10000

typedef struct liste *liste;
typedef struct cell *cell;
typedef struct element element;

struct element{
    short nbre;
    char nbreDigit;
};

struct liste{
    struct cell *deb, *end;
};

struct cell{
    element el;
    struct cell *suiv;
};

#endif
