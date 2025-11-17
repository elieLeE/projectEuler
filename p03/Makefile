#Makefile
#cible: dependances
#commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

CC=gcc
CFLAGS=-std=c99 -Wextra -Wall -Werror# -ansi -pedantic
LDFLAGS=-lm
EXEC=prog
LIBC=../libC/src
SRC= $(wildcard *.c $(LIBC)/mem/mem.c $(LIBC)/math/prime.c\
	 $(LIBC)/logger/logger.c $(LIBC)/vector/vector.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC) cleanSimple

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: cleanSimple clean

cleanSimple:
	rm -rf $(OBJ)

clean: cleanSimple
	rm -rf $(EXEC)
