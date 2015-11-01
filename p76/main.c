#include <stdio.h>
#include <stdlib.h>

int nbrePoss(int n){
    int i=0, compt = 0;
    if(n==1){
	return 1;
    }
    else if(n==2){
	return 2;
    }
    else{
	for(i=n-1; i>=1; i--){
	    printf("nbrePoss => %d\n", i);
	    compt += nbrePoss(i);
	}
	return compt;
    }
}

int main(){
    int tab[100] = {0};
    int n = 5, compt = 1, i;

    for(i=n-1; i>=1; i--){
	if(n-i>n){
	    compt += nbrePoss(i);
	}
	else{
	    compt += nbrePoss(i);
	}
	printf("main => %d ==> %d\n", n-i, compt);
    }
    printf("compt : %d\n", compt);

    return 0;
}
