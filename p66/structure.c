#include "structure.h"

void testDepassement(long long n){
    if(n > LLONG_MAX){
	pritnf("on depasse\n");
	exit(0);
    }
}

long long normeAlpha(alpha a){
    printf("norme => a.a*a.a - a.n*a.b*a.b = %lld*%lld - %lld*%lld*%lld = %lld\n", a.a, a.a, a.n, a.b, a.b, (a.a*a.a - a.n*a.b*a.b));
    long long n = a.a*a.a - a.n*a.b*a.b;
    testDepassement(n);
}

void alphaCarre(alpha *a){
    long long  x = a->a;
    a->a = (a->a*a->a + a->b*a->b*a->n);
    a->b = 2*x*a->b;
    testDepassement(a->a);
    testDepassement(a->b);
}

void alphaCarreSur2(alpha *a){
    alphaCarre(a);
    a->a = a->a/2;
    a->b = a->b/2;
    testDepassement(a->a);
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
    long long x = a->a;
    a->a = a->a*(a->a*a->a + 3*a->b*a->b*a->n)/8;
    a->b = a->b*(3*x*x + a->b*a->b*a->n)/8;
    testDepassement(a->a);
    testDepassement(a->b);
    //return (a.a*a.a*a.a + 3*a.a*a.b*a.b*a.n)/8;
    //newA.b = (3*a.a*a.a*a.b+a.b*a.b*a.b*a.n)/8;
    //newA.n = a.n;
}

void alphaSixSur64(alpha *a){
    long long a2 = a->a*a->a;
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
    testDepassement(a->b);
    //return (a6 + 15*a4*b2*a.n + 15*a2*b4*n2 + n2*a.n*b6)/64;
}

char* visuAlpha(alpha a){
    char *chaine = (char*)calloc(100, sizeof(char));
    sprintf(chaine, "(%lld + %lld*sqrt(%lld))", a.a, a.b, a.n);
    return chaine;
}

alpha nextAlpha(struct search_sol sol, long long m){
    printf("alpha3 : %s\n", visuAlpha(sol.alp));
    struct alpha newA;
    newA.a = (sol.alp.a * m + sol.alp.b * sol.alp.n)/abs(sol.norme);
    newA.b = (sol.alp.a + m * sol.alp.b)/abs(sol.norme);
    newA.n = sol.alp.n;
    testDepassement(newA.a);
    testDepassement(newA.b);
    testDepassement(newA.n);
    printf("newAlpha : %s\n", visuAlpha(newA));
    return newA;
}

long long searchFirstM(long long n){
    long long m1 = floor(sqrt(n));
    long long m2 = m1+1;
    testDepassement(m1);
    /*printf("n : %lld, sqrt(n) : %lld, m1 : %lld, m2 : %lld\n", n, sqrt(n), m1, m2);
    printf("(n - m1*m1) : %lld, (m2*m2 - n) : %lld\n", (n-m1*m1), (m2*m2 - n));*/
    if((n - m1*m1) < (m2*m2 - n)){
	return m1;
    }
    else{
	return m2;
    }
}

long long searchM(struct search_sol sol){
    //printf("sol.m : %lld, sol.norme : %lld, sol.alp.n : %lld\n", sol.m, sol.norme, sol.alp.n);
    long long m = -sol.m, res1 = 0, res2 = 0;
    long long addM = abs(sol.norme);
    printf("ici\n");
    /*if(sol.norme == 0){
	return 0;
    }*/
    while(m<0){
	printf("first boucle, m : %lld\n", m);
	m+=addM;
    }
    printf("ici2\n");
    while((res1=(m*m - sol.alp.n))<0){
	//printf("second boucle\n");
	res2 = res1;
	m+=addM;
	printf("res1 : %lld, m : %lld, addM : %lld\n", res1, m, addM);
    }
    printf("ici3\n");
    res2 = -res2;
    testDepassement(res1);
    testDepassement(res2);
    if(res1 > res2){
	return m-addM;
    }
    else{
	return m;
    }

    return m;
}

alpha searchSol(long long n){
    //printf("recherche de la solution pour n : %lld\n", n);
    search_sol sol;
    sol.alp.a = 1;
    sol.alp.b = 1;
    sol.alp.n = n;
    sol.norme = 1;
    sol.m = 1;
    
    sol.m = searchFirstM(n);
    sol.alp.a = sol.m;
    sol.norme = (sol.alp.a * sol.alp.a) - sol.alp.n;

    return searchSolRec(sol);
}

alpha searchSolRec(struct search_sol sol){
    search_sol s2;
    s2 = sol;
    char c;

    /*printf("searchSolRec, alpha : %s, de norme = %lld avec m = %lld\n", visuAlpha(sol.alp), sol.norme, sol.m);
    printf("alpha1 : %s\n", visuAlpha(sol.alp));
    getchar();*/

    search_sol newSol;
    switch(abs(sol.norme)){
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
	    printf("\tdefault\n");
	    newSol.m = searchM(sol);
	    printf("default2\n");
	    newSol.alp = nextAlpha(sol, newSol.m);
	    printf("default2\n");
	    newSol.norme = normeAlpha(newSol.alp);
	    printf("resultats => alpha : %s, avec m : %lld et norme : %lld\n\n", visuAlpha(newSol.alp), newSol.m, newSol.norme);
	    return searchSolRec(newSol);

    }
}
