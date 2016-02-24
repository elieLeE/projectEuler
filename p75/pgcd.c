#include "pgcd.h"

unsigned int pgcd(unsigned int a, unsigned int b){
    unsigned int div = a/b;
    unsigned int r = a - b*div;
    
    while(r != 0){
	a = b;
	b = r;
    	div = a/b;
	r = a - b*div;
    }
    return b;
}
