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

prog: main.o fichier.o grille.o liste_elem.o liste_elem_imp.o liste_val_poss.o algo.o grille.o 
	gcc -std=c99 -Wall -Wextra -function-declaration -o $@ $^ 

main.c: donnees.h

%.o: %.c
	gcc -std=c99 -Wall -Wextra -o $@ -c $<

clean:
	rm -f *.o prog
