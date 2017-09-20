//faz a inclusão das funcoes
#include "functions.h"

// funcao para abrir um arquivo - espera o arquivo para abrir
void abrir( char tipo [ 3 ] ){

    // verifica se o banco de dados vaii ser nulo
    // se for ele encerra a plicação
    // se nao for segue o jogo
	if( ( bd = fopen( dataBase, tipo ) ) == NULL ){
		printf("\nNão foi possivel abrir o arquivo\n");
		exit(1);
	}

	// final da função
}
