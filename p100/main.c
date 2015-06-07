#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <math.h>

#define NBRE_BIT_PRECISION 10000 

int main(){
    /*do{
      mpf_set_d(t, nbreTotal*2*(nbreTotal-1)+1);
      mpf_sqrt(rac, t);
      mpf_add_ui(nbreBlue, rac, 1);
      mpf_div_ui(nbreBlue, nbreBlue, 2);
      mpf_floor(floorRac, t);
      mpf_floor(nbreBlueFloor, nbreBlue);
      nbreTotal++;
      }while(((mpf_cmp(rac, floorRac)) != 0) & (mpf_cmp(nbreBlue, nbreBlueFloor) != 0));*/

    double b_n = 1, b_n_plus_1 = 0, t_n = 1, t_n_plus_1 = 0;
    mpf_t nbreBlue, rac, floorRac, nbreBlueFloor, t;

    mpf_init2(t,NBRE_BIT_PRECISION);
    mpf_init2(nbreBlue, NBRE_BIT_PRECISION);
    mpf_init2(nbreBlueFloor, NBRE_BIT_PRECISION);
    mpf_init2(rac, NBRE_BIT_PRECISION);
    mpf_init2(floorRac,  NBRE_BIT_PRECISION);

    while(t_n < 1000000000000.0){
	b_n_plus_1 = 3*b_n + 2*t_n -2;
	t_n_plus_1 = 4*b_n + 3*t_n -3;

	b_n = b_n_plus_1;
	t_n = t_n_plus_1;
    }


    mpf_t puis;
    mpf_init(puis);

    double nbreTotal = t_n;
    mpf_set_d(t, 0.0);
    mpf_add_ui(t, t, nbreTotal);
    mpf_mul_ui(t, t, 2);
    mpf_mul_ui(t, t, nbreTotal-1);
    mpf_add_ui(t, t, 1);

    mpf_sqrt(rac, t);
    gmp_printf("t : %Ff, rac : %.*Ff\n", t, NBRE_BIT_PRECISION*2, rac);
    mpf_mul(puis, rac, rac);
    gmp_printf("puis : %Ff, rac : %Ff\n", puis, rac);
    gmp_printf("test => puis : %Ff, rac : %Ff\n", puis, floorRac);
    gmp_printf("t : %Ff, rac : %Ff\n", t, rac);
    mpf_add_ui(nbreBlue, rac, 1);
    mpf_div_ui(nbreBlue, nbreBlue, 2);
    mpf_floor(floorRac, rac);
    mpf_floor(nbreBlueFloor, nbreBlue);

    gmp_printf("nbreTotal : %lf, t : %Ff, rac : %Ff, nbreBlue : %Ff\n", nbreTotal, t, rac, nbreBlue);

    printf("t_n : %lf, b_n : %lf\n", t_n, b_n);

    return 0;
}

