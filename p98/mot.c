#include "mot.h"

unsigned int areAnagramSquare(dataHach *d){
    unsigned long i, n, answ = 0;
    double rac;
    char **mots = affectationMot(d);
    unsigned int *tabVal = my_calloc(26*sizeof(unsigned int));
    unsigned long firstC, lastC; 
    firstCarre(strlen(d->firstMot)-1, &firstC, &lastC);
    setTab(tabVal, d->firstMot, firstC*firstC);

    i = lastC;
    while(i>=firstC){
	setTab(tabVal, d->firstMot, i*i);
	if(verifTab(tabVal, mots[0])){
	    n = valMot(mots[1], tabVal);
	    rac = sqrt(n);
	    if(rac == floor(rac)){
		answ = max (i*i, n);
		break;
	    }
	}
	i--;
    }

    free(tabVal);
    free(mots);
    return answ;
}

unsigned long valMot(char* mot, unsigned int* tabVal){
    int i;
    unsigned long n = 0, mul=1;
    for(i=strlen(mot)-1; i>=0; i--){
	n = n + tabVal[(unsigned char)(mot[i]-65)]*mul;
	mul = mul*10;
    }
    return n;
}

bool egaliteMot(char* s1, char *s2){
    unsigned int i;
    if(strlen(s1) != strlen(s2)){
	return false;
    }
    for(i=0; i<strlen(s1); i++){
	if(s1[i] != s2[i]){
	    return false;
	}
    }
    return true;
}

void maxWords(FILE* f, unsigned int *maxLong, unsigned int* maxSumAscii){
    char s[50];
    unsigned int longMot = 0, sumMot = 0;
    *maxLong = 0;
    *maxSumAscii = 0;
    while(lireMot(f, s)){
	longMot = longeurMot(s);
	sumMot = sumAsciiMot(s);
	*maxLong = max(*maxLong, longMot);
	*maxSumAscii = max(*maxSumAscii, sumMot);
    }
    fseek(f, 0, SEEK_SET);
}

unsigned int longeurMot(char *mot){
    unsigned int longMot = strlen(mot)-1;
    mot[longMot] = '\0';
    return longMot;
}

unsigned int sumAsciiMot(char *mot){
    unsigned int sum = 0, i;
    for(i=0; i<strlen(mot); i++){
	sum = sum + mot[i];
    }
    return sum;
}

bool areAnagramesWords(unsigned char *tab1, unsigned char *tab2){
    unsigned char i;
    for(i=0; i<26; i++){
	if(tab1[i] != tab2[i]){
	    return false;
	}
    }
    return true;
}

void analyseMot(char* mot, unsigned char* tab){
    unsigned int i;
    unsigned int longM = strlen(mot);
    for(i=0; i<longM; i++){
	tab[(unsigned char)(mot[i]-65)]++;
    }
}
