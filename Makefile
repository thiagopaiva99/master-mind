all : mastermind

mastermind: main.o low.o up.o jogo.o consulta_apelido.o jogar.o novo_jogador.o 
	gcc main.o low.o up.o jogo.o consulta_apelido.o jogar.o novo_jogador.o -o mastermind

main.o: main.c
	gcc -c main.c
low.o: low.c
	gcc -c low.c
up.o: up.c
	gcc -c up.c
jogo.o: jogo.c
	gcc -c jogo.c
consulta_apelido.o: consulta_apelido.c
	gcc -c consulta_apelido.c
jogar.o: jogar.c
	gcc -c jogar.c
novo_jogador.o: novo_jogador.c
	gcc -c novo_jogador.c

clean:
	rm *.o
