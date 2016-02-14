#ifndef _SHARED_LISTE_H_
#define _SHARED_LISTE_H_

/*
 * liste generique
 * */

#include <stdbool.h>

typedef struct *liste liste;
struct liste{
    struct liste *suiv;
    void *data;
};

liste* creerListe();
bool listeEmpty(liste l);
void addElement(liste* l, void *e);
//void visuListe(liste l, => via un poointeur de fonction ==> la parcourt est fait dans cette fonction, l'affichage des elements via la fonction dont l'adresse est passé en paramétre
void removeFirstElement(liste *l);
void removeLastElement(liste l);
void removeElementN(liste *l, int n);
void freeListe(liste *l);

#endif
