fibon: fibon.o utils.o
	gcc -Wall -pedantic -ansi fibon.o utils.o -o fibon -lm

fibon.o: fibon.c utils.h
	gcc -Wall -pedantic -ansi -c fibon.c -o fibon.o

utils.o: utils.c utils.h
	gcc -Wall -pedantic -ansi -c utils.c -o utils.o
