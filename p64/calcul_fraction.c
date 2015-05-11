#include "calcul_fraction.h"

int calcul_periode(int n){
    double racine = sqrt(n);
    int a = floor(racine);
    int period = 0, tmp, num = 1.0, denum = -floor(a);
    int first_num = num, first_denum = denum;

    if(a != racine){
	do{
	    a = floor((num)/(racine + denum));
	    tmp = n - denum*denum;
	    if(num != 1){
		tmp = tmp/num;
		num = 1;
	    }
	    denum = -(num*denum+a*tmp);
	    num = tmp;
	    period++;
	}while((first_num != num) | (first_denum != denum));
    }


    return period;
}
