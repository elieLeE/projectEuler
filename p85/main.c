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
    if(new.diff_abs == 16){
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!--- ICI ---!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }

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
	j = i-1;
	calcul = 1;
	new.i = i;
	while(calcul < obj){
	    j++;
	    calcul = first_calcul*sum(j);
	}
	new.j = j;
	new.diff_abs = fabs(calcul - obj);
	printf("after obj => (%d, %d) => %d, %lf\n", i, j, calcul, new.diff_abs);
	j--;
	miseAJourMin(&min, new);

	new.j = j;
	calcul = first_calcul*sum(j);
	new.diff_abs = fabs(calcul - obj);
	printf("before obj => (%d, %d) => %d, %lf\n\n", i, j, calcul, new.diff_abs);
	miseAJourMin(&min, new);
    }
    printf("(%d, %d) => diff min : %lf ==> %d, diff avec obj => %lf\n", min.i, min.j, min.diff_abs, sum(min.i)*sum(min.j), fabs(sum(min.i)*sum(min.j)-obj));
    return new.i * new.j;
}


int main(){
    printf("%d\n", area());

    //printf("%d\n", sum(

    return 0;
}
