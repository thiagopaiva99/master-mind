#include "functions.h"

//INICIAR JOGO
void jogar(){
    char username[15];
    int can_play = 0;

	system("clear");

	printf("+--------------------------------------+\n");
	printf("|                                      |\n");
	printf("|     INFORME O USUÁRIO PARA JOGAR     |\n");
	printf("|                                      |\n");
	printf("+--------------------------------------+\n");

	printf("\nNome de Usuário: ");
	scanf("%s", username);
	can_play = consulta_apelido( username );

	if ( can_play != 1 ) getOut();
	if ( can_play == 1 ) play();
}

void play(){
    printf("+--------------------------------------+\n");
	printf("|                                      |\n");
	printf("|          USUÁRIO CADASTRADO!         |\n");
	printf("|                                      |\n");
	printf("+--------------------------------------+\n");

	printf("\nPressione qualquer tecla para inciar o jogo!");

    getc(stdin);
    getc(stdin);
    jogo();
}

void getOut(){
    int will_register = 2;

    printf("+--------------------------------------+\n");
	printf("|                                      |\n");
	printf("|     USUÁRIO NÃO CADASTRO NO JOGO     |\n");
	printf("|                                      |\n");
	printf("+--------------------------------------+\n");

	printf("\nDeseja se cadastrar agora => [ 1 ] Sim [ 2 ] Não: ");
    scanf("%d", &will_register);

    if ( will_register == 1 ) novo_jogador();
}
