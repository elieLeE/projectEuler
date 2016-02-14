#include "nbre.h"
#include "math.h"
#include "../shared/nbre.h"

#define FIRST_NBRE 987654321
#define LAST_NBRE 321

int main(){
    unsigned long i = 0;

    for(i=FIRST_NBRE; i>=LAST_NBRE; i-=2){
	if(isPandigital(i)){
	    if(isPrime(i)){
		printf("%ld\n", i);
		return 0;
	    }
	}
    }
    return 0;
} 
