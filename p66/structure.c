#include "structure.h"

void testDepassement(long long n){
    if(n > LLONG_MAX){
	pritnf("on depasse\n");
	exit(0);
    }
}

mpz_t* normeAlpha(alpha a){
    //printf("norme => a.a*a.a - a.n*a.b*a.b = %lld*%lld - %lld*%lld*%lld = %lld\n", a.a, a.a, a.n, a.b, a.b, (a.a*a.a - a.n*a.b*a.b));
    mpz_t *n1, n2;
    mpz_init(*n1);
    mpz_mul(*n1, a.a, a.a);
    mpz_init(n2);
    mpz_mul(n2, a.n, a.b);
    mpz_mul(n2, n2, a.b);
    mpz_sub(*n1, *n1, n2);
    return n1;
    //testDepassement(n);
}

void alphaCarre(alpha *a){
    printf("alphaCarre 1\n");
    mpz_t x, n1, n2;
    mpz_init_set(x, a->a);
    mpz_init(n1);
    //printf("alphaCarre 1_1\n");
    mpz_mul(n1, a->a, a->a);
    mpz_init(n2);
    mpz_mul(n2, a->b, a->b);
    mpz_mul(n2, n2, a->n);
    //printf("alphaCarre 1_2\n");
    mpz_sub(n1, n1, n2);
    mpz_set(a->a, n1);
    mpz_mul(x, x, a->b);

    //printf("alphaCarre 1_3\n"); 
    //printf("taille x : %ld, taille a->b : %ld\n", sizeof(x), sizeof(a->b)); 
    //mpz_set(a->b, x);
    /*mpz_clear(a->b);
    mpz_init_set(a->b, x);*/
    printf("alphaCarre 2\n");
    //a->a = (a->a*a->a + a->b*a->b*a->n);
    //a->b = 2*x*a->b;
    /*testDepassement(a->a);
      testDepassement(a->b);*/
}

void alphaCarreSur2(alpha *a){
    printf("alphaCarreSur2 1\n");
    alphaCarre(a);
    mpz_sub_ui(a->a, a->a, 2);
    mpz_sub_ui(a->b, a->b, 2);
    printf("alphaCarreSur2 2\n");
    /*a->a = a->a/2;
      a->b = a->b/2;*/
    /*testDepassement(a->a);
      testDepassement(a->b);
    //alpha newA;
    /*long x = a->a;
    a->a = (a->a*a->a + a->b*a->b*a->n)/2;
    a->b = x*a->b;*/
    //return (a.a*a.a + a.b*a.b*a.n)/2;
    //newA.b = a.a*a.b;
    //newA.n = a.n;
}

void alphaCubeSur8(alpha *a){
    //alpha newA;
    mpz_t x, n1, n2;
    mpz_init_set(x, a->a);
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

    mpz_clear(n1);
    mpz_clear(n2);
    mpz_mul(n1, x, x);
    mpz_mul_ui(n1, n1, 3);
    mpz_mul(n2, a->b, a->b);
    mpz_mul(n2, n2, a->n);
    mpz_add(n1, n1, n2);
    mpz_mul(n1, n1, a->b);
    mpz_div_ui(n1, n1, 8);
    /*a->a = a->a*(a->a*a->a + 3*a->b*a->b*a->n)/8;
      a->b = a->b*(3*x*x + a->b*a->b*a->n)/8;*/
    /*testDepassement(a->a);
      testDepassement(a->b);*/
    //return (a.a*a.a*a.a + 3*a.a*a.b*a.b*a.n)/8;
    //newA.b = (3*a.a*a.a*a.b+a.b*a.b*a.b*a.n)/8;
    //newA.n = a.n;
}

void alphaSixSur64(alpha *a){
    mpz_t a2, a4, a6, b2, b4, b6, n2, x;
    mpz_init(a2);
    mpz_init(a4);
    mpz_init(a6);
    mpz_init(b2);
    mpz_init(b4);
    mpz_init(b6);
    mpz_init(n2);
    mpz_init_set(x, a->a);

    mpz_mul(a2, a->a, a->a);
    mpz_mul(a4, a2, a2);
    mpz_mul(a6, a4, a2);
    mpz_mul(b2, a->b, a->b);
    mpz_mul(b4, b2, b2);
    mpz_mul(n2, a->n, a->n);

    mpz_t m1, m2, m3;
    mpz_init(m1);
    mpz_init(m2);
    mpz_init(m3);
    mpz_mul(m1, a4, b2);
    mpz_mul(m1, m1, a->n);
    mpz_mul_ui(m1, m1, 15);
    mpz_add(m1, m1, a6);
    mpz_mul(m2, a2, b4);
    mpz_mul(m2, m2, n2);
    mpz_mul_ui(m2, m2, 15);
    mpz_add(m1, m1, m2);
    mpz_clear(m2);
    mpz_mul(m2, n2, a->n);
    mpz_mul(m2, m2, b6);
    mpz_add(m1, m1, m2);
    mpz_div_ui(m1, m1, 64);
    mpz_set(a->a, m1);

    mpz_clear(m1);
    mpz_clear(m2);
    mpz_mul(m1, b2, a->n);
    mpz_mul_ui(m1, m1, 3);
    mpz_add(m1, m1, a2);
    mpz_mul(m2, b2, a->n);
    mpz_mul_ui(m3, a2, 3);
    mpz_add(m2, m2, m3);
    mpz_mul(m1, m1, m2);
    mpz_mul(m1, m1, x);
    mpz_mul(m1, m1, a->b);
    mpz_mul_ui(m1, m1, 2);
    mpz_div_ui(m1, m1, 64);
    mpz_set(a->b, m1);

    /*long long a2 = a->a*a->a;
      long long a4 = a2*a2;
      long long a6 = a4*a2;
      long long b2 = a->b*a->b;
      long long b4 = b2*b2;
      long long b6 = b4*b2;
      long long n2 = a->n*a->n;
      long long x = a->a;
      a->a = (a6 + 15*a4*b2*a->n + 15*a2*b4*n2 + n2*a->n*b6)/64;
      a->b = 2*x*a->b*(a2 + 3*b2*a->n)*(3*a2 + b2*a->n)/64;
      testDepassement(a->a);
      testDepassement(a->b);*/
    //return (a6 + 15*a4*b2*a.n + 15*a2*b4*n2 + n2*a.n*b6)/64;
}

char* visuAlpha(alpha a){
    /*char *chaine = (char*)calloc(100, sizeof(char));
      sprintf(chaine, "(%lld + %lld*sqrt(%lld))", a.a, a.b, a.n);*/
    printf("visuAlpha 1\n");
    gmp_printf("alpha : %Zd + %Zd*sqrt(%Zd)\n", a.a, a.b, a.n);
    printf("visuAlpha 2\n");
    //return chaine;
}

alpha nextAlpha(struct search_sol sol, mpz_t m){
    //printf("alpha3 : %s\n", visuAlpha(sol.alp));
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
    mpz_mul(m1, m, sol.alp.b);
    mpz_add(m1, m1, sol.alp.a);
    mpz_div(m1, m1, sol.norme);
    mpz_abs(m1, m1);
    mpz_init_set(newA.b, m1);

    mpz_init_set(newA.n, sol.alp.n);

    /*newA.a = (sol.alp.a * m + sol.alp.b * sol.alp.n)/abs(sol.norme);
      newA.b = (sol.alp.a + m * sol.alp.b)/abs(sol.norme);
      newA.n = sol.alp.n;*/


    /*testDepassement(newA.a);
      testDepassement(newA.b);
      testDepassement(newA.n);*/
    //printf("newAlpha : %s\n", visuAlpha(newA));
    return newA;
}

mpz_t* searchFirstM(int n){
    printf("searchFirstM 0_0\n");
    mpz_t *m1, *m2, m3, m4, mpzN;
    m1 = calloc(1, sizeof(mpz_t));
    m2 = calloc(1, sizeof(mpz_t));
    mpz_init(*m1);
    printf("searchFirstM 0_1_0\n");
    mpz_init(*m2);
    printf("searchFirstM 0_1_1_0\n");
    mpz_init(m3);
    printf("searchFirstM 0_1_1\n");
    mpz_init(m4);
    printf("searchFirstM 0_1\n");
    mpz_init_set_ui(mpzN, n);
    mpz_root(*m1, mpzN, 2);
    //mpz_sqrt(*m1, mpzN);
    //gmp_floor(*m1, *m1);
    //*m1 = gmp_root(*m1, 1);
    mpz_add_ui(*m2, *m1, 1);

    printf("searchFirstM 0\n");
    mpz_add_ui(m3, m3, n);
    mpz_mul(*m1, *m1, *m1);
    mpz_sub(m3, m3, *m1);

    mpz_mul(m4, *m2, *m2);
    mpz_sub_ui(m4, m4, n);
    if(mpz_cmp(m3, m4) > 0){
	return m1;
    }
    else{
	return m2;
    }
    /*long long m1 = floor(sqrt(n));
      long long m2 = m1+1;*/
    //testDepassement(m1);
    /*printf("n : %lld, sqrt(n) : %lld, m1 : %lld, m2 : %lld\n", n, sqrt(n), m1, m2);
      printf("(n - m1*m1) : %lld, (m2*m2 - n) : %lld\n", (n-m1*m1), (m2*m2 - n));*/
    /*if((n - m1*m1) < (m2*m2 - n)){
      return m1;
      }
      else{
      return m2;
      }*/
}

mpz_t* searchM(struct search_sol sol){
    //printf("sol.m : %lld, sol.norme : %lld, sol.alp.n : %lld\n", sol.m, sol.norme, sol.alp.n);
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

    /*long long m = -sol.m, res1 = 0, res2 = 0;
      long long addM = abs(sol.norme);*/
    //printf("ici\n");
    /*if(sol.norme == 0){
      return 0;
      }*/

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

/*if(res1 > res2){
  return m-addM;
  }
  else{
  return m;
  }

  return m;*/
}

alpha searchSol(int n){
    //printf("recherche de la solution pour n : %lld\n", n);
    search_sol sol;
    mpz_init_set_ui(sol.alp.a, 1);
    mpz_init_set_ui(sol.alp.b, 1);
    mpz_init_set_ui(sol.alp.n, n);
    mpz_init_set_ui(sol.norme, 1);
    mpz_init_set_ui(sol.m, 1);

    printf("dans searchSol0\n");
    mpz_set(sol.m, *searchFirstM(n));
    gmp_printf("sol.m : %Zd\n", sol.m);
    printf("dans searchSol1_0_0\n");
    mpz_set(sol.alp.a, sol.m);
    printf("dans searchSol1_0\n");
    mpz_mul(sol.norme, sol.alp.a, sol.alp.a);
    mpz_sub(sol.norme, sol.norme, sol.alp.n);

    printf("dans searchSol1\n");

    /*sol.alp.a = 1;
      sol.alp.b = 1;
      sol.alp.n = n;
      sol.norme = 1;
      sol.m = 1;

      sol.m = searchFirstM(n);
      sol.alp.a = sol.m;
      sol.norme = (sol.alp.a * sol.alp.a) - sol.alp.n;*/

    return searchSolRec(sol);
}

alpha searchSolRec(struct search_sol sol){
    search_sol s2;
    s2 = sol;
    char c;
    printf("dans searchSolRec 1_0\n");

    search_sol newSol;
    mpz_init(newSol.alp.a);
    mpz_init(newSol.alp.b);
    mpz_init(newSol.alp.n);
    mpz_init(newSol.norme);
    mpz_init(newSol.m);
    printf("dans searchSolRec 1_1\n");

    /*printf("searchSolRec, alpha : %s, de norme = %lld avec m = %lld\n", visuAlpha(sol.alp), sol.norme, sol.m);
      printf("alpha1 : %s\n", visuAlpha(sol.alp));
      getchar();*/
    if(mpz_cmp_ui(sol.norme, 0) == 0){
	printf("test ok\n");
    }
    else{
	printf("test ok\n");
    }
    printf("apres test\n");

    if(mpz_cmp_ui(sol.norme, 0) == 0){
	printf("dans searchSolRec 1_2_0\n");
	mpz_set_ui(newSol.alp.a, -1);
	mpz_set_ui(newSol.alp.b, -1);
	mpz_set(newSol.alp.n, sol.alp.n);
	mpz_set_ui(newSol.norme, 0);
	mpz_set(newSol.m, sol.m);
	return newSol.alp;
    }

    /*if(sol.norme == 0){
      newSol.alp.a = -1;
      newSol.alp.b = -1;
      newSol.alp.n = sol.alp.n;
      newSol.norme = 0;
      newSol.m = sol.m;
      return newSol.alp;
      }*/
    mpz_abs(sol.norme, sol.norme);
    if(mpz_cmp_ui(sol.norme, 1)==0){
	printf("dans searchSolRec 1_2_1\n");
	alphaCarre(&sol.alp);
	printf("dans searchSolRec 1_2_2\n");
	return sol.alp;
    }
    else if(mpz_cmp_ui(sol.norme, 2)==0){
	printf("dans searchSolRec 1_2_2\n");
	alphaCarreSur2(&(sol.alp));
	printf("dans searchSolRec 1_2_3\n");
	return sol.alp;
    }
    else if(mpz_cmp_ui(sol.norme, 4)==0){
	printf("dans searchSolRec 1_2_3\n");
	mpz_t xa, xb, xn;
	mpz_init_set(xa, sol.alp.a);
	mpz_mod_ui(xa, xa, 2);
	mpz_init_set(xb, sol.alp.b);
	mpz_mod_ui(xb, xb, 2);
	mpz_init_set(xn, sol.alp.n);
	mpz_mod_ui(xn, xn, 2);

	if(mpz_cmp_ui(xa, 0)==0 && mpz_cmp(xb, 0)){
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
	else if(mpz_cmp(xn, 0)==0){
	    alphaCarreSur2(&(sol.alp));
	    mpz_div_ui(sol.alp.a, sol.alp.a, 2);
	    mpz_div_ui(sol.alp.b, sol.alp.b, 2);
	    return sol.alp;
	}
	else{
	    if(mpz_cmp_ui(sol.norme, 0)>0){
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
	//printf("\tdefault\n");
	printf("dans searchSolRec 1_2_3\n");
	mpz_set(newSol.m, *searchM(sol));
	printf("dans searchSolRec 1_3\n");
	//printf("default2\n");
	//mpz_set(newSol.alp, nextAlpha(sol, newSol.m));
	newSol.alp = nextAlpha(sol, newSol.m);
	//printf("default2\n");
	mpz_set(newSol.norme, *normeAlpha(newSol.alp));
	//printf("resultats => alpha : %s, avec m : %lld et norme : %lld\n\n", visuAlpha(newSol.alp), newSol.m, newSol.norme);
	return searchSolRec(newSol);
    }
}



/*switch(abs(sol.norme)){
  case 1:
//printf("\tcase 1\n");
alphaCarre(&(sol.alp));
return sol.alp;

case 2:
//printf("\tcase 2\n");
alphaCarreSur2(&(sol.alp));
return sol.alp;

case 4:
//printf("\tcase 4\n");
//if(sol.alp.a%2 == 0 & sol.alp.b%2 == 0){
if(sol.alp.a/2 == floor(sol.alp.a/2) && sol.alp.b/2 == floor(sol.alp.b/2)){
//printf("\t\talpha pair\n");
if(sol.norme > 0){
//printf("\t\t\tnorme positive\n");
sol.alp.a = sol.alp.a/2;
sol.alp.b = sol.alp.b/2;
return sol.alp;
}
else{
//printf("\t\t\tnorme negative\n");
alphaCarreSur2(&(sol.alp));
sol.alp.a = sol.alp.a/2;
sol.alp.b = sol.alp.b/2;
return sol.alp;
}
}
//else if(sol.alp.n%2 == 0){
else if(sol.alp.n/2 == floor(sol.alp.n/2)){
//printf("\t\tn pair\n");
alphaCarreSur2(&(sol.alp));
sol.alp.a = sol.alp.a/2;
sol.alp.b = sol.alp.b/2;
return sol.alp;
}
else{
//printf("\t\telse\n");
if(sol.norme > 0){
//printf("\t\t\tnorme positive\n");
alphaCubeSur8(&(sol.alp));
return sol.alp;
}
else{
//printf("\t\t\tnorme negative\n");
alphaSixSur64(&(sol.alp));
return sol.alp;
}
}
break;

default:
//printf("\tdefault\n");
newSol.m = searchM(sol);
//printf("default2\n");
newSol.alp = nextAlpha(sol, newSol.m);
//printf("default2\n");
newSol.norme = normeAlpha(newSol.alp);
//printf("resultats => alpha : %s, avec m : %lld et norme : %lld\n\n", visuAlpha(newSol.alp), newSol.m, newSol.norme);
return searchSolRec(newSol);

}*/
//}
