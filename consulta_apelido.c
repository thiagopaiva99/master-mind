// faz inclusao das funcoes
#include "functions.h"

// funcao para consultar se o jogador ja existe - espera o username do jogador
int consulta_apelido( char username[ 15 ] ){

    // arquivo para servir de banco de dados
	FILE *bd;

    // arquivo que vai ser o banco de dados
	char *dataBase = "players.txt";

    // linha em que vai se encontra o usuario caso ele exista
	char linha[50];

    // variavel que vai servir para dizer se vai existir o usuario ou nao
	int existe = 1;

    // verifica se o banco de dados vaii ser nulo
    // se for ele encerra a plicação
    // se nao for segue o jogo
	if( ( bd = fopen( dataBase, "r" ) ) == NULL ){
		printf("\nNão foi possivel abrir o arquivo\n");
		exit(1);
	}

    // enquanto conseguir ler o arquivo de usuarios
    while ( fgets( linha, sizeof( linha ), bd ) != NULL )
        // verifica se na linha atual existe o username
        // se existir fecha a conexao com bd e retorna a variavel existe
    	if ( strstr( linha, username ) != NULL ){
            fclose( bd );
            return existe;
    }

    // final da funcao
}
