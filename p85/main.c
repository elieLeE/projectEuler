#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct S_min S_min;
struct S_min{
    double diff_abs;
    int i, j;
};

int sum(int n){
    return n*(n+1)/2;
}

void miseAJourMin(S_min *min, S_min new){
    if(min->diff_abs > new.diff_abs){
	*min = new;
    }
}

int area(){
    int i, j;
    int first_calcul, calcul;
    int obj = 2000000;
    S_min min, new;
    min.diff_abs = 20000000;

    for(i=1; i<=1500; i++){
	first_calcul = sum(i);
	j = i;
	calcul = 1;
	new.i = i;
	calcul = first_calcul*sum(j);
	if(calcul > obj){
	    break;
	}
	while(calcul < obj){
	    j++;
	    calcul = first_calcul*sum(j);
	}
	new.j = j;
	new.diff_abs = fabs(calcul - obj);
	miseAJourMin(&min, new);

	j--;
	new.j = j;
	calcul = first_calcul*sum(j);
	new.diff_abs = fabs(calcul - obj);
	miseAJourMin(&min, new);
    }
    return min.i * min.j;
}


int main(){
    printf("%d\n", area());

    return 0;
}
