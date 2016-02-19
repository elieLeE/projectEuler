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
#include "fichier.h"
#include "../shared/alloc.h"

int main(){
    FILE* f = ouvFichier("p098_words.txt", "r");
    unsigned int maxLongMot, maxSumMotAscii;
    liste** tabHach; 

    maxWords(f, &maxLongMot, &maxSumMotAscii);
    printf("maxLongMot : %d, maxSumMotAscii : %d\n", maxLongMot, maxSumMotAscii);

    tabHach = my_calloc(maxLongMot, maxSumMotAscii, sizeof(

    fermerFichier(&f);

    return 0;
}


