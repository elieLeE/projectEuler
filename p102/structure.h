#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define NBRE_TRIANGLE 1000

typedef struct triangle triangle;
typedef struct point point;
typedef enum posPoint posPoint;

enum posPoint{
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT};

struct point{
    int x, y;
};

struct triangle{
    point tab[3];
};

void affTri(triangle t);
void affTabTri(triangle t[]);

bool canContainOrigin(triangle t);
bool containOrigin(triangle t);
void posOfPoint(point p, bool pos[]);
bool isOpposite(bool pos[4]);

#endif
