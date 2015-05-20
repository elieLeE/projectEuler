#ifndef _DONNEES_H_
#define _DONNEES_H_

#define NBRE_MAX 1000000

typedef struct liste *liste;

struct liste{
    int nbre;
    struct liste *suiv;
};

#endif

