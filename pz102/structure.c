#include "structure.h"

void affTri(triangle t){
    int j = 0;
    for(j=0; j<3; j++){
	printf("%d, %d, ", t.tab[j].x, t.tab[j].y);
    }
}

void affTabTri(triangle t[]){
    int i = 0;
    for(i=0; i<NBRE_TRIANGLE; i++){
	affTri(t[i]);
	printf("\n");
    }
}

void posOfPoint(point p, bool pos[4]){
    if(p.x<0){
	if(p.y<0){
	    pos[BOTTOM_LEFT] = true;
	}
	else if(p.y>0){
	    pos[TOP_LEFT] = true;
	}
	else{
	    pos[BOTTOM_LEFT] = true;
	    pos[TOP_LEFT] = true;
	}
    }
    else if(p.x>0){
	if(p.y<0){
	    pos[BOTTOM_RIGHT] = true;
	}
	else if(p.y>0){
	    pos[TOP_RIGHT] = true;
	}
	else{
	    pos[BOTTOM_RIGHT] = true;
	    pos[TOP_RIGHT] = true;
	}
    }
    else{
	if(p.y<0){
	    pos[BOTTOM_LEFT] = true;
	    pos[BOTTOM_RIGHT] = true;
	}
	else if(p.y>0){
	    pos[TOP_RIGHT] = true;
	    pos[TOP_LEFT] = true;
	}
    }
}

bool containOrigin(triangle t){
    bool tab[3];
    //calcul des coordonnées barycentriques => (xm-xa)(ym-yb)-(xm-xb)(ym-ya)... avec xm = 0 et ym = 0
    tab[0] = ((t.tab[0].x * t.tab[1].y) - (t.tab[1].x * t.tab[0].y))>0;
    tab[1] = ((t.tab[1].x * t.tab[2].y) - (t.tab[2].x * t.tab[1].y))>0;
    tab[2] = ((t.tab[2].x * t.tab[0].y) - (t.tab[0].x * t.tab[2].y))>0;

    return (tab[0] && tab[1] && tab[2]) || ((!tab[0]) && (!tab[1]) && (!tab[2]));
}

bool canContainOrigin(triangle t){
    bool posP[4] = {false};
    int i=0;
    int nbreDeZones = 0;

    for(i=0; i<3; i++){
	posOfPoint(t.tab[i], posP);
    }
    for(i=0; i<4; i++){
	if(posP[i]){
	    nbreDeZones++;
	}
    }
    if(nbreDeZones==1){
	return false;
    }
    else if(nbreDeZones==3){
	return true;
    }
    else {
	return isOpposite(posP);
    }
}

bool isOpposite(bool pos[4]){
    return (pos[TOP_LEFT] && pos[BOTTOM_RIGHT])
	|| (pos[BOTTOM_LEFT] && pos[TOP_RIGHT]);
}

