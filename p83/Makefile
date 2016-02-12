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

prog: main.o lecture.o matrice.o graphe.o alloc.o
	gcc -std=c99 -Wall -Wextra -o $@ $^

%.o: %.c
	gcc -std=c99 -Wall -Wextra -o $@ -c $<

clean:
	rm -f *.o prog
