#include "functions.h"

struct player {
	char username[15];
	char name[20];
	char age[2];
} player;

//CADASTRO DO JOGADOR
void novo_jogador(void){
	FILE *bd;
	char *dataBase = "players.txt";

	if( ( bd = fopen( dataBase, "a+t" ) ) == NULL ) return terminate();

	system( "clear" );
	fseek( bd, 0L, SEEK_END );

    printf( "+-----------------------+\n" );
    printf( "|                       |\n" );
	printf( "|  CADASTRO DE JOGADOR  |\n" );
	printf( "|                       |\n" );
	printf( "+-----------------------+\n" );

    printf( "\nNome: " );
	scanf(  "%s", player.name );
	strtoupper( player.name );

	printf( "\nNome de Usuário: " );
	scanf(  "%s", player.username );

	printf( "\nIdade: " );
	scanf(  "%s", player.age );

	//INSERE OS DADOS NO ARQUIVO
	fprintf( bd, "%s:%s:%s\n", player.username, player.name, player.age);
	printf("\n Cadastro Efetuado\n\n\n");

	fclose(bd);
}

void terminate(){
    printf("\nO arquivo nao pode ser aberto!\n");
    exit(1);
}
