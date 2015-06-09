#include "structure.h"

long normeAlpha(alpha a){
    return a.a*a.a - a.n*a.b*a.b;
}

alpha alphaCarreSur2(alpha a){
    alpha newA;
    newA.a = (a.a*a.a + a.b*a.b*a.n)/2;
    newA.b = a.a*a.b;
    newA.n = a.n;
    return newA;
}

alpha alphaCubeSur8(alpha a){
    alpha newA;
    newA.a = (a.a*a.a*a.a + 3*a.a*a.b*a.b*a.n)/8;
    newA.b = (3*a.a*a.a*a.b+a.b*a.b*a.b*a.n)/8;
    newA.n = a.n;
    return newA;
}

char* visuAlpha(alpha a){
    char *chaine = (char*)calloc(100, sizeof(char));
    sprintf(chaine, "(%ld + %ld*sqrt(%ld))", a.a, a.b, a.n);
    return chaine;
}
