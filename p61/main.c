#include "nbre.h"
#include "liste.h"
#include "remplissage.h"

#define NRBE_FIGURATE_NUMBERS 2	    //1 est deja fait

int main(){
    l_elem listeNbreOctagonal;
    l_tabhach tabHachNbre[5][100];
    int tabIndice[5] = {-1, -1, -1, -1, -1};
    bool nbreFait[5] = {false, false, false, false, false};
    c_elem p;
    c_tabhach t[5];
    bool continuer = true;

    remplissage(&listeNbreOctagonal, tabHachNbre);

    /*visuTabHach(tabHachNbre[0], "nbreTriangulaires");
    visuTabHach(tabHachNbre[1], "nbreCarres");
    visuTabHach(tabHachNbre[2], "nbrePentagonaux");
    visuTabHach(tabHachNbre[3], "nbreHexagonaux");
    visuTabHach(tabHachNbre[4], "nbreHeptagonaux");
    visuListe(listeNbreOctagonal.deb, "nbreOctagonaux");*/

    p = listeNbreOctagonal.deb;
    continuer = true;
    while(!isEmpty(p) && continuer){
	while(nextNbre(nbreFait, &tabIndice[0], tabHachNbre, p->left) && continuer){
	    t[0] = (tabHachNbre[tabIndice[0]][p->left]).deb;
	    while(!tabHachEmpty(t[0]) && continuer){
		while(nextNbre(nbreFait, &tabIndice[1], tabHachNbre, t[0]->right) && continuer){
		    t[1] = (tabHachNbre[tabIndice[1]][t[0]->right]).deb;
		    while(!tabHachEmpty(t[1]) && continuer){
			while(nextNbre(nbreFait, &tabIndice[2], tabHachNbre, t[1]->right) && continuer){
			    t[2] = (tabHachNbre[tabIndice[2]][t[1]->right]).deb;
			    while(!tabHachEmpty(t[2]) && continuer){
				while(nextNbre(nbreFait, &tabIndice[3], tabHachNbre, t[2]->right) && continuer){
				    t[3] = (tabHachNbre[tabIndice[3]][t[2]->right]).deb;
				    while(!tabHachEmpty(t[3]) && continuer){
					continuer = !dernierNbre(tabHachNbre, p->right, t[3]->right, nbreFait, &tabIndice[4]);
					if(continuer){
					    t[3] = t[3]->suiv;
					    tabIndice[4] = -1;
					}
				    }
				}
				if(continuer){
				    if(tabIndice[3] >= 0){
					nbreFait[tabIndice[3]] = false;
				    }
				    tabIndice[3] = -1;
				    t[2] = t[2]->suiv;
				}
			    }
			}
			if(continuer){
			    if(tabIndice[2] >= 0){
				nbreFait[tabIndice[2]] = false;
			    }
			    t[1] = t[1]->suiv;
			    tabIndice[2] = -1;
			}
		    }
		}
		if(continuer){
		    t[0] = t[0]->suiv;
		    if(tabIndice[1] >= 0){
			nbreFait[tabIndice[1]] = false;
		    }
		    tabIndice[1] = -1;
		}
	    }
	}
	if(continuer){
	    p = p->suiv;
	    if(tabIndice[0] >= 0){
		nbreFait[tabIndice[0]] = false;
	    }
	    tabIndice[0] = -1;
	}
    }

    printf("%d\n", (p->left)*100+p->right+(t[0]->right)*100+p->left+(t[1]->right)*100+t[0]->right+(t[2]->right)*100+t[1]->right+
           (t[3]->right)*100+t[2]->right+(p->right)*100+t[3]->right);
    return 0;
}



