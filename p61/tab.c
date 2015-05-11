#include "tab.h"

void remplissageTabHachNbreTriangulaire(l_tabhach tab[100]){
    int left_partie = 0, right_partie = 1;
    int dist = 2;
    int ajout_dist = 1, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    ajoutElemTabHach(&tab[right_partie], left_partie);
	    //tab[left_partie][right_partie] = true;
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}

void remplissageTabHachNbreCarre(l_tabhach tab[100]){
    int left_partie = 0, right_partie = 1;
    int dist = 3;
    int ajout_dist = 2, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    //tab[left_partie][right_partie] = true;
	    ajoutElemTabHach(&tab[right_partie], left_partie);
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}

void remplissageTabHachNbrePentagonal(l_tabhach tab[100]){
    int left_partie = 0, right_partie = 1;
    int dist = 4;
    int ajout_dist = 3, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    //tab[left_partie][right_partie] = true;
	    ajoutElemTabHach(&tab[right_partie], left_partie);
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}

void remplissageTabHachNbreHexagonal(l_tabhach tab[100]){
    int left_partie = 0, right_partie = 1;
    int dist = 5;
    int ajout_dist = 4, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    //tab[left_partie][right_partie] = true;
	    ajoutElemTabHach(&tab[right_partie], left_partie);
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}
void remplissageTabHachNbreHeptagonal(l_tabhach tab[100]){
    int left_partie = 0, right_partie = 1;
    int dist = 6;
    int ajout_dist = 5, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    //tab[left_partie][right_partie] = true;
	    ajoutElemTabHach(&tab[right_partie], left_partie);
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}
void remplissageTabHachNbreOctagonal(l_tabhach tab[100]){
    int left_partie = 0, right_partie = 1;
    int dist = 7;
    int ajout_dist = 6, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    //tab[left_partie][right_partie] = true;
	    ajoutElemTabHach(&tab[right_partie], left_partie);
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}

void remplissageTabCarre(bool tab[100][100]){
    int left_partie = 0, right_partie = 1;
    int dist = 3;
    int ajout_dist = 2, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    tab[left_partie][right_partie] = true;
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}
void remplissageTabHeptagonal(bool tab[100][100]){
    int left_partie = 0, right_partie = 1;
    int dist = 6;
    int ajout_dist = 5, retenue = 0;
    while(left_partie<10){
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
    while(left_partie < 100){
	if(right_partie >= 10){
	    tab[left_partie][right_partie] = true;
	}
	right_partie += dist;
	while(right_partie >=100){
	    right_partie-=100;
	    retenue++;
	}
	left_partie+=retenue;
	retenue = 0;
	dist += ajout_dist;
    }
}

void afftabNbre(bool tab[100][100], char *name){
    printf("%s\n", name);
    int i, j = 0;
    for(i=0; i<100; i++){
	for(j=0; j<100; j++){
	    if(tab[i][j]){
		printf("(%d, %d) ", i, j);
	    }
	}
    }
    printf("\n");
}
