#makefile

all: prog clean

prog : main.o
	gcc -o $@ $^ -lm -lgmp

clean:
	rm *.o prog
