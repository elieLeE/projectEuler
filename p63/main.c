#include "nbre.h"

int main(){
    int compt = 0, i =1;
    int tmp;
    do{
	tmp = nbre_integer(i);
	compt += tmp;
	i++;
    }while(tmp != 0);

    printf("compt : %d\n", compt);

    return 0;
}
