#Makefile
#cible: dependances
#	commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

EXE: prog

all: clean prog

prog: main.o nbre.o liste.o tabhach.o remplissage.o
	gcc -o $@ $^ -lm

%.o: %.c
	gcc -o $@ -c $<

clean:
	rm -f *.o prog
