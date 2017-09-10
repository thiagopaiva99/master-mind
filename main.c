#include "functions.h"

FILE *bd;
char *dataBase = "players.txt";

void main(void) {
	char opcao[2], op;

	do{
		do{
            system( "clear" );
            printf( "+---------------------------+\n" );
            printf( "|                           |\n" );
            printf( "|         MASTERMIND        |\n" );
            printf( "|                           |\n" );
            printf( "+---------------------------+\n\n" );
            printf( " Selecione a opção desejada: \n" );
            printf( "\n [ N ] Novo jogador" );
            printf( "\n [ J ] Jogar" );
            printf( "\n [ P ] Perfil" );
            printf( "\n [ R ] Ranking" );
            printf( "\n [ C ] Como Jogar" );
            printf( "\n [ S ] Sair" );
            printf( "\n\nEscolha a opção: " );

			scanf( "%s", opcao );
			op = tolower( *opcao );
		} while( !strchr( "njprcs", op ) );

        choise(op);

	}while(1);
}

void perfil(){
	system("clear");
	printf("perfil");
}

void ranking(){
	system("clear");
	printf("ranking");
}
void comojogar(){
	system("clear");
	printf("como jogar");
}
void sair(void){
	system("clear");
	exit(0);
}

void choise(char op){
    switch( op ){
        case 'n' : novo_jogador(); break;
        case 'j' : jogar(); break;
        case 'p' : perfil(); break;
        case 'r' : ranking(); break;
        case 'c' : comojogar(); break;
        case 's' : sair(); break;
    }
}


