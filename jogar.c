// faz a inclusao das funcoes
#include "functions.h"

// funcao que se encarrega de iniciar o jogo ou nao, caso haja usuario
void jogar(){

    // variavel para buscar o nome de usuario
    char username[15];

    // variavel para verificar se pode jogar
    int can_play = 0;

    // limpa a tela
	system("clear");

    // printa o header bonitnho
	printf("+--------------------------------------+\n");
	printf("|                                      |\n");
	printf("|     INFORME O USUÁRIO PARA JOGAR     |\n");
	printf("|                                      |\n");
	printf("+--------------------------------------+\n");

    // pede pelo nome de usuario do jogado
	printf("\nNome de Usuário: ");
	scanf("%s", username);

	// a variavel can_play assume o valor do consulta_apelido
	// caso haja jogador com esse username, a funcao retorna 1
	// caso nao haja jogador com esse username, a funcao retorna um valor diferente de 1
	can_play = consulta_apelido( username );

    // verifica se pode jogar
    // nao pode? chama a funcao getOut()
	if ( can_play != 1 ) getOut();

	// pode? chama a funcao play passando o nome do usuario que vai jogar
	if ( can_play == 1 ) play( username );

	// final da funcao
}

// funcao que se encarrega de chamar o jogo
void play( char username[20] ){

    // printa o header bonitinho
    printf("+--------------------------------------+\n");
	printf("|                                      |\n");
	printf("|          USUÁRIO CADASTRADO!         |\n");
	printf("|                                      |\n");
	printf("+--------------------------------------+\n");

    // pede para pressionar qualquer tecla para poder limpar o buffer
	printf("\nPressione qualquer tecla para inciar o jogo!");

    //  limpa o buffer
    getc(stdin);
    getc(stdin);

    // chama o jogo em si
    jogo( username );

    // final da funcao
}

// funcao que se encarrega de fazer a chamada da funcao de criar novo usario, ou sair, caso ele deseje
void getOut(){
    // colocando o valor 2 (Nao) como padrão da variavel que vai decidir se vamos criar um novo usuario
    int will_register = 2;

    // printa o header bonitinho
    printf("+--------------------------------------+\n");
	printf("|                                      |\n");
	printf("|     USUÁRIO NÃO CADASTRO NO JOGO     |\n");
	printf("|                                      |\n");
	printf("+--------------------------------------+\n");

	// pergunta se deseja cadastrar um novo usuario
	printf("\nDeseja se cadastrar agora => [ 1 ] Sim [ 2 ] Não: ");
    scanf("%d", &will_register);

    // se a reposta for 1 (Sim) ele chama a funcao de criar novo usuario
    if ( will_register == 1 ) novo_jogador();

    // final da funcao
}
