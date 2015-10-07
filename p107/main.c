#include <stdio.h>
#include "structure.h"
#include "fichier.h"
#include "network.h"
#include "tri.h"


int main(){
    int poidsInit = 0, poidsFinal = 0;
    int nbreCoTot, nbreCoMax;

    arete *tabArete;
    sommet tabSommets[NBRE_SOMMETS];

    FILE *f = ouvFichier("p107_network.txt");

    nbreMaxCo(f, &nbreCoMax, &nbreCoTot);
    tabArete = allocArete(nbreCoTot);
    initTabSommets(tabSommets, nbreCoMax);

    lectureFichier(f, tabArete);

    poidsInit = poidsNetwork(tabArete, nbreCoTot);
    
    trierTabArete(tabArete, nbreCoTot); 
    //affTabArete(tabArete, nbreCoTot);

    remplissageTabSommets(tabSommets, tabArete, nbreCoTot);
    
    reductionNetwork(tabArete, tabSommets, nbreCoTot);

    //affTabArete(tabArete, nbreCoTot);
    //affTabSommet(tabSommets);

    poidsFinal = poidsNetwork(tabArete, nbreCoTot);

    printf("poidsInit : %d, poidsFinal : %d, poids saving : %d\n", poidsInit, poidsFinal, (poidsInit - poidsFinal));

    free(tabArete);
    libTabSommets(tabSommets); 
    fermetureFichier(&f);

    return 0;
}
