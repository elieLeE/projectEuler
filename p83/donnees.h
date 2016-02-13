#ifndef _DONNEES_H_
#define _DONNEES_H_

#include <stdbool.h>

#define MODE 0
#define BIG 10000000
#define SMALL 0

#define DEBUG 0

#if MODE 
#define TAILLE_MATRICE 5
#else
#define TAILLE_MATRICE 80
#endif

typedef struct sommet sommet;
typedef struct pos pos;
typedef enum etat etat;

enum etat{
    NON_ATTEIGNABLE,
    ATTEIGNABLE,
    ADDED
};

struct pos{
    int lig, col;
};

struct sommet{
    unsigned int coutSom, coutChemin;
    etat e;
    int nbreVoisins;
    sommet* voisins[4];
    pos p;
};

#endif
