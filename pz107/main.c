#include <stdio.h>
#include "structure.h"
#include "fichier.h"
#include "network.h"
#include "tri.h"
#include "../shared/fichier.h"
#include "../shared/alloc.h"

int main(){
    int poidsInit = 0, poidsFinal = 0;
    int nbreCoTot, nbreCoMax;

    arete *tabArete;
    sommet tabSommets[NBRE_SOMMETS];

    FILE *f = ouvFichier("p107_network.txt", "r");

    nbreMaxCo(f, &nbreCoMax, &nbreCoTot);
    tabArete = my_calloc(nbreCoTot*sizeof(arete));
    initTabSommets(tabSommets, nbreCoMax);

    lectureFichier(f, tabArete);

    poidsInit = poidsNetwork(tabArete, nbreCoTot);
    
    trierTabArete(tabArete, nbreCoTot); 

    remplissageTabSommets(tabSommets, tabArete, nbreCoTot);
    
    reductionNetwork(tabArete, tabSommets, nbreCoTot);

    poidsFinal = poidsNetwork(tabArete, nbreCoTot);

    printf("%d\n", (poidsInit - poidsFinal));

    free(tabArete);
    libTabSommets(tabSommets); 
    fermerFichier(&f);

    return 0;
}
