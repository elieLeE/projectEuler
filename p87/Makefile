#Makefile
#cible: dependances
#commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

EXE: prog

all: clean prog1 prog2

prog1: main1.o nbre.o
	gcc -o $@ $^ -lm

main1.c: nbre.h

prog2: main2.o nbre.o
	gcc -o $@ $^ -lm

main2.c: nbre.h

%.o: %.c
	gcc -o $@ -c $<

clean:
	rm -f *.o prog
