#Makefile
#cible: dependances
#commandes
#$@ : cible
#$< : nom de la premiere dependance
#$^ : liste des dependances
#$? : liste des dependances plus recentes que la cible
#$* : nom du fichier sans le suffixe

CC=gcc
CFLAGS=-std=c99 -Wextra -Wall# -ansi -pedantic
LDFLAGS=
EXEC=prog
LIB_C=../libC/src
SRC= $(wildcard *.c $(LIB_C)/math/nber_helper.c $(LIB_C)/mem/mem.c\
	 $(LIB_C)/logger/logger.c $(LIB_C)/vector/vector.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC) cleanSimple

debug: CFLAGS += -DDDEBUG -g
debug: LDFLAGS += -DDDEBUG -g
debug: all

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: cleanSimple clean

cleanSimple:
	rm -rf $(OBJ)

clean: cleanSimple
	rm -rf $(EXEC)
