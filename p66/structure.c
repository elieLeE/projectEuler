#include "structure.h"

mpz_t* normeAlpha(alpha a){
    mpz_t n1, n2, *m1;
    m1 = calloc(1, sizeof(mpz_t));
    mpz_init(*m1);
    mpz_init(n1);
    mpz_mul(n1, a.a, a.a);
    mpz_init(n2);
    mpz_mul(n2, a.n, a.b);
    mpz_mul(n2, n2, a.b);
    mpz_sub(*m1, n1, n2);

    return m1;
}

void alphaMul(alpha *a1, alpha a2){
    mpz_t m1, m2, x;
    mpz_init(m1);
    mpz_init(m2);
    mpz_init_set(x, a1->a);

    mpz_mul(m1, a1->a, a2.a);
    mpz_mul(m2, a1->b, a2.b);
    mpz_mul(m2, m2, a1->n);
    mpz_add(a1->a, m1, m2);

    mpz_clear(m1);
    mpz_clear(m2);
    mpz_mul(m1, x, a2.b);
    mpz_mul(m2, a1->b, a2.a);
    mpz_add(a1->b, m1, m2);
}

void alphaCarre(alpha *a){
    mpz_t n1, n2;

    //calcul de a->a
    mpz_init(n1);
    mpz_mul(n1, a->a, a->a);
    mpz_init(n2);
    mpz_mul(n2, a->b, a->b);
    mpz_mul(n2, n2, a->n);
    mpz_add(n1, n1, n2);

    //calcul de a->b
    mpz_mul(a->b, a->a, a->b);
    mpz_set(a->a, n1);
}

void alphaCarreSur2(alpha *a){
    alphaCarre(a);
    mpz_cdiv_q_ui(a->a, a->a, 2);
    //on ne div a->b pas par 2 car on ne l'a pas multiplié par
    //2 dans alphaCarre ((a+b)² => a² + b² + 2ab)
}

void alphaCubeSur8(alpha *a){
    mpz_t x, n1, n2;
    mpz_init_set(x, a->a);

    //calcul de a->a
    mpz_init(n1);
    mpz_init(n2);
    mpz_mul(n1, a->a, a->a);
    mpz_mul(n2, a->b, a->b);
    mpz_mul(n2, n2, a->n);
    mpz_mul_ui(n2, n2, 3);
    mpz_add(n1, n1, n2);
    mpz_mul(n1, n1, a->a);
    mpz_div_ui(n1, n1, 8);
    mpz_set(a->a, n1);

    //calcul de a->b
    mpz_clear(n1);
    mpz_clear(n2);
    mpz_init(n1);
    mpz_init(n2);
    mpz_mul(n1, x, x);
    mpz_mul_ui(n1, n1, 3);
    mpz_mul(n2, a->b, a->b);
    mpz_mul(n2, n2, a->n);
    mpz_add(n1, n1, n2);
    mpz_mul(n1, n1, a->b);
    mpz_div_ui(n1, n1, 8);
    mpz_set(a->b, n1);
}

void alphaSixSur64(alpha *a){
    alphaCubeSur8(a);
    alphaCarre(a);
    mpz_mul_ui(a->b, a->b, 2);
}

void visuAlpha(alpha a){
    gmp_printf("alpha : %Zd + %Zd*sqrt(%Zd)\n", a.a, a.b, a.n);
}

alpha nextAlpha(struct search_sol sol, mpz_t m){
    struct alpha newA;
    mpz_t m1, m2;
    mpz_init(m1);
    mpz_init(m2);
    mpz_mul(m1, sol.alp.a, m);
    mpz_mul(m2, sol.alp.b, sol.alp.n);
    mpz_add(m1, m1, m2);
    mpz_div(m1, m1, sol.norme);
    mpz_abs(m1, m1);
    mpz_init_set(newA.a, m1);

    mpz_clear(m1);
    mpz_clear(m2);
    mpz_init(m1);
    mpz_init(m2);
    mpz_mul(m1, m, sol.alp.b);
    mpz_add(m1, m1, sol.alp.a);
    mpz_div(m1, m1, sol.norme);
    mpz_abs(m1, m1);
    mpz_init_set(newA.b, m1);

    mpz_init_set(newA.n, sol.alp.n);

    return newA;
}

mpz_t* searchFirstM(int n){
    mpz_t *m1, *m2, m3, m4, m5, mpzN;
    m1 = calloc(1, sizeof(mpz_t));
    m2 = calloc(1, sizeof(mpz_t));
    mpz_init(*m1);
    mpz_init(*m2);
    mpz_init(m3);
    mpz_init(m4);
    mpz_init(m5);
    mpz_init_set_ui(mpzN, n);
    mpz_root(*m1, mpzN, 2);
    mpz_add_ui(*m2, *m1, 1);

    mpz_mul(m3, *m1, *m1);
    mpz_set_ui(m5, n);
    mpz_sub(m3, m5, m3);

    mpz_mul(m4, *m2, *m2);
    mpz_sub_ui(m4, m4, n);

    if(mpz_cmp(m3, m4) < 0){
	free(m2);
	return m1;
    }
    else{
	free(m1);
	return m2;
    }
}

mpz_t* searchM(struct search_sol sol){
    mpz_t *m;
    m = calloc(1, sizeof(mpz_t));
    mpz_t res1, res2, addM, zero, inter;
    mpz_init(zero);
    mpz_init(*m);
    mpz_init(res1);
    mpz_init(res2);
    mpz_init(inter);
    mpz_init_set(addM, sol.norme);
    mpz_abs(addM, addM);
    mpz_sub(*m, res1, sol.m);

    while(mpz_cmp(*m, zero)<0){
	mpz_add(*m, *m, addM);
    }
    while(true){
	mpz_mul(inter, *m, *m);
	mpz_sub(inter, inter, sol.alp.n);
	mpz_set(res1, inter);
	if(mpz_cmp(inter, zero)<0){
	    mpz_set(res2, res1);
	    mpz_add(*m, *m, addM);
	}
	else{
	    break;
	}
    }

    mpz_sub(res2, zero, res2);
    mpz_abs(res2, res2);
    if(mpz_cmp(res1, res2) > 0){
	mpz_sub(*m, *m, addM);
    }
    return m;
}

alpha searchSol(int n){
    search_sol sol;
    mpz_init_set_ui(sol.alp.a, 1);
    mpz_init_set_ui(sol.alp.b, 1);
    mpz_init_set_ui(sol.alp.n, n);
    mpz_init_set_ui(sol.norme, 1);
    mpz_init_set_ui(sol.m, 1);

    mpz_set(sol.m, *searchFirstM(n));
    mpz_set(sol.alp.a, sol.m);
    mpz_mul(sol.norme, sol.alp.a, sol.alp.a);
    mpz_sub(sol.norme, sol.norme, sol.alp.n);


    return searchSolRec(sol);
}

alpha searchSolRec(struct search_sol sol){
    search_sol newSol;
    mpz_init(newSol.alp.a);
    mpz_init(newSol.alp.b);
    mpz_init(newSol.alp.n);
    mpz_set(newSol.alp.n, sol.alp.n);
    mpz_init(newSol.norme);
    mpz_init(newSol.m);

    if(mpz_cmp_ui(sol.norme, 0) == 0){
	mpz_set_ui(newSol.alp.a, -1);
	mpz_set_ui(newSol.alp.b, -1);
	mpz_set(newSol.alp.n, sol.alp.n);
	mpz_set_ui(newSol.norme, 0);
	mpz_set(newSol.m, sol.m);
	return newSol.alp;
    }

    bool signNorme = mpz_cmp_ui(sol.norme, 0)>0;
    mpz_abs(sol.norme, sol.norme);
    if(mpz_cmp_ui(sol.norme, 1)==0){
	alphaCarre(&sol.alp);
	return sol.alp;
    }
    else if(mpz_cmp_ui(sol.norme, 2)==0){
	alphaCarreSur2(&(sol.alp));
	return sol.alp;
    }
    else if(mpz_cmp_ui(sol.norme, 4)==0){
	mpz_t xa, xb, xn;
	mpz_init_set(xa, sol.alp.a);
	mpz_mod_ui(xa, xa, 2);
	mpz_init_set(xb, sol.alp.b);
	mpz_mod_ui(xb, xb, 2);
	mpz_init_set(xn, sol.alp.n);
	mpz_mod_ui(xn, xn, 2);

	if(mpz_cmp_ui(xa, 0)==0 && mpz_cmp_ui(xb, 0)==0){
	    if(mpz_cmp_ui(sol.norme, 0)>0){
		mpz_div_ui(sol.alp.a, sol.alp.a, 2);
		mpz_div_ui(sol.alp.b, sol.alp.b, 2);
		return sol.alp;
	    }
	    else{
		alphaCarreSur2(&(sol.alp));
		mpz_div_ui(sol.alp.a, sol.alp.a, 2);
		mpz_div_ui(sol.alp.b, sol.alp.b, 2);
		return sol.alp;
	    }
	}
	else if(mpz_cmp_ui(xn, 0)==0){
	    alphaCarreSur2(&(sol.alp));
	    mpz_div_ui(sol.alp.a, sol.alp.a, 2);
	    mpz_div_ui(sol.alp.b, sol.alp.b, 2);
	    return sol.alp;
	}
	else{
	    alphaCarreSur2(&(sol.alp));
	    if(signNorme){
		alphaCubeSur8(&(sol.alp));
		return sol.alp;
	    }
	    else{
		alphaSixSur64(&(sol.alp));
		return sol.alp;
	    }
	}
    }
    else{
	mpz_set(newSol.m, *searchM(sol));
	newSol.alp = nextAlpha(sol, newSol.m);
	mpz_set(newSol.norme, *normeAlpha(newSol.alp));
	mpz_clear(sol.m);
	mpz_clear(sol.norme);
	return searchSolRec(newSol);
    }
}
