#include "structure.h"

long normeAlpha(alpha a){
    return a.a*a.a - a.n*a.b*a.b;
}

long alphaCarreSur2(alpha a){
    //alpha newA;
    return (a.a*a.a + a.b*a.b*a.n)/2;
    //newA.b = a.a*a.b;
    //newA.n = a.n;
}

long alphaCubeSur8(alpha a){
    //alpha newA;
    return (a.a*a.a*a.a + 3*a.a*a.b*a.b*a.n)/8;
    //newA.b = (3*a.a*a.a*a.b+a.b*a.b*a.b*a.n)/8;
    //newA.n = a.n;
}

long alphaSixSur64(alpha a){
    long a2 = a.a*a.a;
    long a4 = a2*a2;
    long a6 = a4*a2;
    long b2 = a.b*a.b;
    long b4 = b2*b2;
    long b6 = b4*b2;
    long n2 = a.n*a.n;
    return (a6 + 15*a4*b2*a.n + 15*a2*b4*n2 + n2*a.n*b6)/64;
}

char* visuAlpha(alpha a){
    char *chaine = (char*)calloc(100, sizeof(char));
    sprintf(chaine, "(%ld + %ld*sqrt(%ld))", a.a, a.b, a.n);
    return chaine;
}

alpha nextAlpha(struct search_sol sol, long m){
    struct alpha newA;
    newA.a = (sol.alp.a * m)/sol.norme;
    newA.b = (sol.alp.a + m * sol.alp.b)/sol.norme;

    return newA;
}

long searchM(struct search_sol sol){
    long m = -sol.m, res1, res2;
    while(m<0){
	m+=sol.norme;
    }
    while(res1=(m*m - sol.alp.n)<0){
	res2 = res1;
	m+=sol.norme;
    }
    res1 = -res1;
    if(res1 > res2){
	return m-sol.norme;
    }
    else{
	return m;
    }

    return m;
}

long searchSol(long n){
    printf("recherche de la solution pour n : %ld\n", n);
    search_sol sol;
    sol.alp.a = 1;
    sol.alp.b = 1;
    sol.alp.n = n;
    sol.norme = 1;
    sol.m = 1;
    
    sol.m = searchM(sol);
    sol.alp.a = sol.m;
    sol.norme = (sol.alp.a * sol.alp.a) + sol.alp.n;

    return searchSolRec(sol);
}

long searchSolRec(struct search_sol sol){
    search_sol s2;
    s2 = sol;
    char c;

    printf("searchSolRec, alpha : %s, de norme = %ld avec m = %ld\n", visuAlpha(sol.alp), sol.norme, sol.m);
    scanf("%c", &c);

    switch(abs(sol.norme)){
	case 1:
	    printf("\tcase 1\n");
	    return sol.alp.a;

	case 2:
	    printf("\tcase 2\n");
	    return alphaCarreSur2(sol.alp);

	case 4:
	    printf("\tcase 4\n");
	    if(sol.alp.a%2 == 0 & sol.alp.b%2 == 0){
		printf("\t\talpha pair\n");
		if(sol.norme > 0){
		    printf("\t\t\tnorme positive\n");
		    return sol.alp.a/2;
		}
		else{
		    printf("\t\t\tnorme negative\n");
		    return alphaCarreSur2(sol.alp)/2;
		}
	    }
	    else if(sol.alp.n%2 == 0){
		printf("\t\tn pair\n");
		return alphaCarreSur2(sol.alp)/2;
	    }
	    else{
		printf("\t\telse\n");
		if(sol.norme > 0){
		    printf("\t\t\tnorme positive\n");
		    return alphaCubeSur8(sol.alp);
		}
		else{
		    printf("\t\t\tnorme negative\n");
		    return alphaSixSur64(sol.alp);
		}
	    }
	    break;

	default:
	    printf("\tdefault\n");
	    search_sol newSol;
	    newSol.m = searchM(sol);
	    newSol.alp = nextAlpha(sol, newSol.m);
	    newSol.norme = normeAlpha(sol.alp);
	    return searchSolRec(sol);

    }
}




    
