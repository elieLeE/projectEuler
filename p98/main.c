/*
 * tableau de hachage contenant l'ensemble des mots => le criteres de triage est la somme ascii des lettres des mots
 * puis liste de liste de mots
 *
 * peux aussi faire tableau de hachage a deux etages => nbre de lettres, puis somme ascii des lettres, puis liste de liste
 *
 * Enfin, si une liste de mot a au moins 2 poss => on teste ==> on affecte a chaque lettre une valeur aleatoire entre 1 et 9 (pas de 0).
 * => en brute force pour les anagrammes des mots
 * */

#include <stdio.h>
#include <stdlib.h>
#include "../shared/fichier.h"
#include "../shared/alloc.h"
#include "../shared/liste.h"
#include "fichier.h"
#include "tabHach.h"
#include "mot.h"
#include "visu.h"

int main(){
    FILE* f = ouvFichier("p098_words.txt", "r");
    unsigned int maxLongMot, maxSumMotAscii;
    liste*** tabhach; 

    maxWords(f, &maxLongMot, &maxSumMotAscii);

    /*
     * simplfie le parcours dans le tab
     * */
    maxLongMot++;
    maxSumMotAscii++;

    tabhach = (liste ***)allocTab2D(maxLongMot, maxSumMotAscii, sizeof(struct liste*));

    remplissageTabHach(f, tabhach);

    printf("%d\n", maxSquare(tabhach, maxLongMot, maxSumMotAscii));
    
    liberationTabHach(tabhach, maxLongMot, maxSumMotAscii);
    fermerFichier(&f);

    return 0;
}


