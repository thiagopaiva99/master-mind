all : mastermind

mastermind: main.o strtolower.o strtoupper.o jogo.o consulta_apelido.o jogar.o novo_jogador.o 
	gcc main.o strtolower.o strtoupper.o jogo.o consulta_apelido.o jogar.o novo_jogador.o -o mastermind

main.o: main.c
	gcc -c main.c
strtolower.o: strtolower.c
	gcc -c strtolower.c
strtoupper.o: strtoupper.c
	gcc -c strtoupper.c
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
