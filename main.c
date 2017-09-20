// faz a inclusao das funcoes
#include "functions.h"

// variavel global do banco de dados
FILE *bd;

// variavel global do arquivo de banco de dados
char *dataBase = "players.txt";

// funcao principal do jogo
void main(void) {

    // variavel da opção que o jogador vai escolher
	char opcao[2], op;

    // while para mostrar o menu
	do{
		do{

            // limpa a tela
            system( "clear" );

            // printa o menu com as opções dispoinveis
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

            // verifica qual qual opção e chama a devida funcao
			scanf( "%s", opcao );

			// transforma a opção digitada para minusculo
			op = tolower( *opcao );
		} while( !strchr( "njprcs", op ) );

        // chama a funcao para escolher qual funcao chamar, loco nao?
        choise(op);

	}while(1);
}

// funcao de perfil
void perfil(){
	system("clear");
	printf("perfil");
}

// funcao do ranking
void ranking(){
	system("clear");
	printf("ranking");
}

// funcao de como jogar
void comojogar(){
	system("clear");
	printf("como jogar");
}

// funcao de sair do jogo
void sair(void){
	system("clear");
	exit(0);
}

// funcao para escolher as funcoes
void choise(char op){

    // verifica qual a opção escolhida e chama a devida funcao
    switch( op ){
        case 'n' : novo_jogador(); break;
        case 'j' : jogar(); break;
        case 'p' : perfil(); break;
        case 'r' : ranking(); break;
        case 'c' : comojogar(); break;
        case 's' : sair(); break;
    }

    // final da funcao
}


