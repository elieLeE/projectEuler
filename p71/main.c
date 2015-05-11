#include <stdio.h>
#include <stdlib.h>

#define COMP (double)((3*1.0)/7)
#define LIMITE_Y 1000000.0

int main(){
    printf("COMP : %f\n", COMP);
    double x = 1.0, y = 1.0, x_sur_y = x/y, max = 0.0, max_n, max_d;

    while(y<LIMITE_Y){
	if(x_sur_y >= COMP){
	    y++;
	}
	else{
	    if(x_sur_y > max){
		max = x_sur_y;
		max_n = x;
		max_d = y;
	    }
	    x++;
	}
	x_sur_y = x/y;
    }

    printf("max : %f, max_n : %f, max_d : %f\n", max, max_n, max_d);
    return 0;
}
