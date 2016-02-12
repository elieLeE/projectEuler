#ifndef _DONNEES_H_
#define _DONNEES_H_

#include <stdbool.h>

#define MODE 1
#define BIG 10000000
#define SMALL 0

#if MODE 
#define TAILLE_MATRICE 5
#else
#define TAILLE_MATRICE 80
#endif

typedef struct sommet sommet;
typedef struct pos pos;

struct sommet{
    unsigned int coutSom, coutChemin;
    bool ajoute;
    int nbreVoisins;
    sommet* voisins[4];
};

struct pos{
    int lig, col;
};

#endif
