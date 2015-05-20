#include "liste.h"
#include "nbre.h"

int main(){
    int i = 0;
    char c;

    liste l = creerListe();
    remplissageListe(&(l->end));
    //visuListe(l->deb);

    cell p1 = l->deb, p2 = NULL, p3 = NULL, p4 = NULL, p5 = NULL;
    element tab[5];

    while(p1 !=NULL){
	p2 = p1->suiv;
	tab[0] = p1->el;
	while(p2!=NULL){
	    if(isPerm(p1->el, p2->el)){
		tab[1] = p2->el;
		p3 = p2->suiv;
		while(p3!=NULL){
		    if(isPermTab(p3->el, tab, 2)){
			tab[2] = p3->el;
			p4 = p3->suiv;
			while(p4!=NULL){
			    if(isPermTab(p4->el, tab, 3)){
				tab[3] = p4->el;
				p5 = p4->suiv;
				while(p5!=NULL){
				    if(isPermTab(p5->el, tab, 4)){
					printf("\np1 : %d, p2 : %d, p3 : %d, p4 : %d, p5 : %d\n", p1->el.nbre, p2->el.nbre, p3->el.nbre, p4->el.nbre, p5->el.nbre);
					return 0;
				    }
				    p5 = p5->suiv;
				}
			    }
			    p4 = p4->suiv;
			}
		    }
		    p3 = p3->suiv;
		}
	    }
	    p2 = p2->suiv;
	}
	p1 = p1->suiv;
    }

    return 0;
}

