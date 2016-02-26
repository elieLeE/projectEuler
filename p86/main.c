#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

#define LIMITE 2000
#define PRECISION 0.0000000001
#define DEBUG 0

typedef struct cuboid cuboid;
struct cuboid{
    unsigned int l, L, H;
};

void calculMinMpz(mpf_t *minX, unsigned int a, unsigned int b, unsigned int c){
    mpf_init(*minX);
    mpf_set_ui(*minX, 1.0*a*b);
    mpf_div_ui(*minX, *minX, 1.0*(a+c));
}

void calculWayMpz(mpf_t *way, unsigned int a, unsigned int b, unsigned int c){
    mpf_init(*way);
    mpf_t minX, x, y;
    mpf_init(x);
    mpf_init(y);

    calculMinMpz(&minX, a, b, c);

    mpf_mul(x, minX, minX);
    mpf_add_ui(x, x, (a*a));
    mpf_sqrt(x, x);

    mpf_set_ui(y, b);
    mpf_sub(y, y, minX);
    mpf_mul(y, y, y);
    mpf_add_ui(y, y, c*c);
    mpf_sqrt(y, y);

    mpf_add(*way, x, y);
}

void minMpz(mpf_t *minD, mpf_t a, mpf_t b){
    if(mpf_cmp(a, b) > 0){
	mpf_set(*minD, b);
    }
    mpf_set(*minD, a);
}

bool shortestWayInteger(cuboid *c){
    //mpf_t w1, w2, w3, minW, minWF, minWF2, minW2, minW3, diffRel;
    mpf_t minW, minWF, minWF2, minW2, minW3;
    static mpf_t previous;
    static bool b = false;
    if(!b){
        mpf_init(previous);
    }
    b = true;
    mpf_init(minWF);
    mpf_init(minWF2);
    mpf_init(minW2);
    mpf_init(minW3);
    calculWayMpz(&minW, c->l, c->L, c->H);
    /*calculWayMpz(&w1, c->l, c->L, c->H);
    calculWayMpz(&w2, c->L, c->l, c->H);
    calculWayMpz(&w3, c->L, c->H, c->l);*/
    /*minMpz(&minW, w1, w2);
    minMpz(&minW, minW, w3);*/
    mpf_floor(minWF, minW);
    mpf_add_ui(minWF2, minWF, 1);
    mpf_sub(minW2, minW, minWF);
    mpf_sub(minW3, minWF2, minW);
    /*mpf_sub(previous, minW, previous);
    gmp_printf("actual : %10Ff, diff : %10Ff\n", minW, previous);
    mpf_set(previous, minW);
    getchar();*/
    if((mpf_cmp_d(minW2, PRECISION) < 0) || (mpf_cmp_d(minW3, PRECISION) < 0)){
	return true;
    }
    return false;
}

unsigned int nbreShortestWayInteger(unsigned int m){
    unsigned int compt = 0;
    cuboid c;
    for(c.H=1; c.H<=m; c.H++){
	for(c.l=c.H; c.l<=m; c.l++){
	    for(c.L=c.l; c.L<=m; c.L++){
		if(shortestWayInteger(&c)){
		    compt++;
		}
	    }
	}
    }
    return compt;
}

int main(){
    cuboid c;
    c.L = 6;
    c.l = 5;
    c.H = 3;
    unsigned int compt = 0;
    unsigned int m = 1;
    unsigned int i;
    unsigned int tab[1000] = {0};

    m = 1840;
    m = 0;
    printf("%d => %d\n", m, nbreShortestWayInteger(m));
    unsigned int oldH = 0, oldH2 = 0;

    do{
	m++;
	//compt = nbreShortestWayInteger(m);
	//printf("m : %d\n", m);
	compt = 0;
	c.L = m;
	for(c.H=1; c.H<=m; c.H++){
	    for(c.l=c.H; c.l<=m; c.l++){
		//printf("\t(%d, %d, %d)\n", c.L, c.l, c.H);
		if(shortestWayInteger(&c)){
		    //printf("(%d, %d, %d)\n", c.L, c.l, c.H);
		    //printf("take\n");
		    compt++;
		    //break;
		    /*if(oldH == c.H){
			if(oldH2 == c.H){
			    printf("c.H : %d, oldH : %d, oldH2 : %d\n", c.H, oldH, oldH2);
			    getchar();
			}
			oldH2 = c.H;
		    }
		    else{
			oldH2 = 0;
		    }
		    oldH = c.H;*/
		}
	    }
	}
	//printf("\n");
	compt = compt + tab[m-1];
	tab[m] = compt;
	//printf("%d => %d\n", m, compt);
	if(m>=999){
	    break;
	}
    }while(compt < LIMITE);

    /*for(i=0; i<=m; i++){
	printf("%d => %d\n", i, tab[i]);
    }*/
    printf("m : %d\n", m);
    printf("compt : %d\n", compt);

    return 0;
}
