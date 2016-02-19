#include <stdio.h>
#include <stdlib.h>
#include "../../liste.h"

void visuElement(void *data){
    printf("%d, ", *((int *)data));
}

int main(){
    liste* l = creerListe();

    int a = 1;

    addElementFirst(&l, &a, sizeof(int));
    a++;
    addElementFirst(&l, &a, sizeof(int));
    a++;
    //addElementLast(l, &a, sizeof(int));

    removeLastElement(l);
    visuListe(l, (void(*)(void *))visuElement);

    freeListe(&l);

    return 0;
}
