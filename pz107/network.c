#include "network.h"

/**
 * reductionNetwork
 * pour l'ensemble des aretes
 *    si areteSupprimable
 *       si otherPath vrai
 *          on supprime l'arete => tabArete[i].etat = false
 *                              => tabSommet[tabArete[i].n1].nbreCoRest--
 *                                 tabSommet[tabArete[i].n2].nbreCoRest--
 *                              => removeSom(tabSommet[tabArete[i].n1].sommetAccess, tabArete[i].n2).
 *                                  => la meilleur solution serait à priori de disposer dans chaque sommet
 *                                  des pointeurs sur les aretes permettant les connexions.
 *       fin si
 *    fin si
 * fin pour
 *
 */

/**
 * otherPath
 * tab <- nous dit quel noeuds ont deja ete analyses
 * si destination pas dans noued.connection
 *    tab[noeudCourant] = true
 *    pour l'ensemble des noeuds connectes au noeudCourant
 *       si pas encore analyse (tab false) et noeud accessible
 *          si analyse(noeud)
 *             return true
 *          fin if
 *      fin si
 *    fin pour
 * fin si
 * return false
 *
 */

bool areteSupprimable(sommet tabSommet[], arete a){
    if(tabSommet[a.n1].nbreCoRest>1){
        if(tabSommet[a.n2].nbreCoRest>1){
            return true;
        }
    }
    return false;
}

bool otherPathFound(sommet s, int somCible){
    int i = 0;
    for(i=0; i<s.nbreCoInit; i++){
        if(s.tabArete[i]->etat && s.indSomCo[i]==somCible){
            return true;
        }
    }
    return false;
}

bool searchOtherPath(sommet s[], int somAc, bool somDone[], int sommetCible){
    int i = 0;
    somDone[somAc] = true;
    if(otherPathFound(s[somAc], sommetCible)){
        return true;
    }
    for(i=0; i<s[somAc].nbreCoInit; i++){
        if(s[somAc].tabArete[i]->etat && (!somDone[s[somAc].indSomCo[i]])){
            if(searchOtherPath(s, s[somAc].indSomCo[i], somDone, sommetCible)){
                return true;
            }
        }
    }
    return false;
}

void initSomDone(bool somDone[]){
    int i = 0;
    for(i=0; i<NBRE_SOMMETS; i++){
	somDone[i] = false;
    }
}

bool otherPath(sommet s[], int sommetDepart, int sommetCible){
    static bool somDone[NBRE_SOMMETS] = {false};
    initSomDone(somDone);
    somDone[sommetDepart] = true;
    int i = 0;
    for(i=0; i<s[sommetDepart].nbreCoInit; i++){
	if(s[sommetDepart].tabArete[i]->etat && s[sommetDepart].indSomCo[i] != sommetCible){
	    if(searchOtherPath(s, s[sommetDepart].indSomCo[i], somDone, sommetCible)){
		return true;
	    }
	}
    }
    return false;
}

void reductionNetwork(arete tabArete[], sommet tabSommet[], int nbreArete){
    int i = 0;
    for(i=nbreArete-1; i>=0; i--){
        if(areteSupprimable(tabSommet, tabArete[i])){
            if(otherPath(tabSommet, tabArete[i].n1, tabArete[i].n2)){
                //suppression
                tabSommet[tabArete[i].n1].nbreCoRest--;
                tabSommet[tabArete[i].n2].nbreCoRest--;
                tabArete[i].etat = false;
            }
        }
    }
}

int poidsNetwork(arete tab[], int taille){
    int i = 0, poids = 0;
    for(i=0; i<taille; i++){
	if(tab[i].etat){
	    poids += tab[i].val;
	}
    }
    return poids;
}
