all : mastermind

mastermind: main.o low.o up.o jogo.o
	gcc main.o low.o up.o jogo.o -o mastermind

main.o: main.c
	gcc -c main.c
low.o: low.c
	gcc -c low.c
up.o: up.c
	gcc -c up.c
jogo.o: jogo.c
	gcc -c jogo.c

clean:
	rm *.o
