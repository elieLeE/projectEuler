#ifndef _TYPE_DONNEES_H_
#define _TYPE_DONNEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct l_elem l_elem;
typedef struct c_elem *c_elem;
typedef struct l_tabhach l_tabhach;
typedef struct c_tabhach *c_tabhach;

struct l_tabhach{
    struct c_tabhach *end, *deb;
};

struct c_tabhach{
    unsigned char right;
    struct c_tabhach *suiv;
};

struct l_elem{
    struct c_elem *deb, *end;
};

struct c_elem{
    unsigned char left, right;
    struct c_elem* suiv;
};

#endif
