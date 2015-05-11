#include "nbre.h"
#include "tab.h"
#include "liste.h"
#include "remplissage.h"

#define NRBE_FIGURATE_NUMBERS 2	    //1 est deja fait

void reInitTab(bool tab[100][100], char taille){
    char i = 0, j = 0;
    for(i=0; i<taille; i++){
	for(j=0; j<100; j++){
	    tab[i][j] = false;
	}
    }
}

void affTypeNbre(char left, char right, char ind, char numEtape){
    char i = 0;
    for(i=0; i<numEtape; i++){
	printf("\t");
    }
    printf("etape %d => nbre", numEtape);
    switch(ind){
	case 0 : 
	    printf("Triangulaire, test avec ");
	    break;
	case 1 : 
	    printf("Carre, test avec ");
	    break;
	case 2 : 
	    printf("Pentagonal, test avec ");
	    break;
	case 3 : 
	    printf("Hexagonal, test avec ");
	    break;
	case 4 : 
	    printf("Heptagonal, test avec ");
	    break;

	default : 
	    printf("type inconnu\n");
    }
    printf("%d, %d\n", left, right);
}

void affAnnulationNbre(char numEtape, char ind){
    char i = 0;
    for(i=0; i<numEtape; i++){
	printf("\t");
    }
    printf("etape %d a refaire => nbre", numEtape);
    switch(ind){
	case 0 : 
	    printf("Triangulaire");
	    break;
	case 1 : 
	    printf("Carre");
	    break;
	case 2 : 
	    printf("Pentagonal");
	    break;
	case 3 : 
	    printf("Hexagonal");
	    break;
	case 4 : 
	    printf("Heptagonal");
	    break;
    }
    printf("\n");
}

int main(){
    l_elem listeNbreOctagonal;
    l_tabhach tabHachNbre[5][100];
    char tabIndice[5] = {0};
    bool nbreFait[5] = {false, false, false, false, false};
    char nbrePrec[5] = {0};
    c_elem p;
    c_tabhach t[5];
    bool continuer = true;
    char c, i = 0;

    remplissage(&listeNbreOctagonal, tabHachNbre);

    visuTabHach(tabHachNbre[0], "nbreTriangulaires");
    visuTabHach(tabHachNbre[1], "nbreCarres");
    visuTabHach(tabHachNbre[2], "nbrePentagonaux");
    visuTabHach(tabHachNbre[3], "nbreHexagonaux");
    visuTabHach(tabHachNbre[4], "nbreHeptagonaux");
    visuListe(listeNbreOctagonal.deb, "nbreOctagonaux");

    p = listeNbreOctagonal.deb;
    continuer = true;
    while(!isEmpty(p) && continuer){
	printf("while 1\n");
	printf("etape 1 => nbreOctagonal, test avec (%d, %d)\n", p->left, p->right);
	scanf("%c", &c);
	while(nextNbre(nbreFait, &tabIndice[0], tabHachNbre, p->left) && continuer){
	    printf("while 2\n");
	    t[0] = (tabHachNbre[tabIndice[0]][p->left]).deb;
	    scanf("%c", &c);
	    while(!tabHachEmpty(t[0]) && continuer){
		printf("while 3\n");
		affTypeNbre(t[0]->right, p->left, tabIndice[0], 2);
		while(nextNbre(nbreFait, &tabIndice[1], tabHachNbre, t[0]->right) && continuer){
		    printf("while 4\n");
		    t[1] = (tabHachNbre[tabIndice[1]][t[0]->right]).deb;
		    scanf("%c", &c);
		    while(!tabHachEmpty(t[1]) && continuer){
			printf("while 5\n");
			affTypeNbre(t[1]->right, t[0]->right, tabIndice[1], 3);
			while(nextNbre(nbreFait, &tabIndice[2], tabHachNbre, t[1]->right) && continuer){
			    printf("while 6\n");
			    t[2] = (tabHachNbre[tabIndice[2]][t[1]->right]).deb;
			    scanf("%c", &c);
			    while(!tabHachEmpty(t[2]) && continuer){
				printf("while 7\n");
				affTypeNbre(t[2]->right, t[1]->right, tabIndice[2], 4);
				while(nextNbre(nbreFait, &tabIndice[3], tabHachNbre, t[2]->right) && continuer){
				    printf("while 8\n");
				    t[3] = (tabHachNbre[tabIndice[3]][t[2]->right]).deb;
				    scanf("%c", &c);
				    while(!tabHachEmpty(t[3]) && continuer){
					printf("while 9\n");
					affTypeNbre(t[3]->right, t[2]->right, tabIndice[3], 5);
					continuer = !dernierNbre(tabHachNbre, p->right, t[3]->right, nbreFait, &tabIndice[4]);
					affTypeNbre(p->right, t[3]->right, tabIndice[4], 6);
					t[3] = t[3]->suiv;
					if(continuer){
					    affAnnulationNbre(5, tabIndice[3]);
					    tabIndice[4] = 0;
					}
				    }
				    printf("fin du while 9\n");
				    scanf("%c", &c);
				}
				printf("fin du while 8\n");
				if(continuer){
				    affAnnulationNbre(4, tabIndice[2]);
				    printf("nbreFait[%d] passe a false\n", tabIndice[3]);
				    nbreFait[tabIndice[3]] = false;
				    tabIndice[3] = 0;
				    t[2] = t[2]->suiv;
				}
			    }
			    printf("fin du while 7\n");
			}
			printf("fin du while 6\n");
			if(continuer){
			    affAnnulationNbre(3, tabIndice[1]);
			    nbreFait[tabIndice[2]] = false;
			    t[1] = t[1]->suiv;
			    tabIndice[2] = 0;
			}
		    }
		    printf("fin du while 5\n");
		}
		printf("fin du while 4\n");
		if(continuer){
		    affAnnulationNbre(2, tabIndice[0]);
		    t[0] = t[0]->suiv;
		    nbreFait[tabIndice[1]] = false;
		    tabIndice[1] = 0;
		}
	    }
	    printf("fin du while 3\n");
	}
	printf("fin du while 2\n");
	if(continuer){
	    printf("etape 1 a refaire => nbre Octagonal\n");
	    p = p->suiv;
	    nbreFait[tabIndice[0]] = false;
	    tabIndice[0] = 0;
	    printf("\n");
	}
    }
    return 0;
}



