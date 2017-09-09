#include "prot_func.h"

//INICIAR JOGO
void jogar(){

    char apelido[15];
    int iresultado=0;

    //setlocale(LC_ALL, "Portuguese");//para acentuação
	system("clear");
	printf("## INICIANDO JOGO ##\n");
	printf("--------------------\n\n");

	printf("----------------------------------------\n");
	printf("- É NECESSARIO ACESSAR COM SEU APELIDO -\n");
	printf("----------------------------------------\n");

	printf("Seu apelido.: ");
	scanf("%s",apelido);
	iresultado = consulta_apelido(apelido);//função para consultar no arquivo o apelido

	if(iresultado != 1){
        	printf("\n *Apelido não cadastrado!!\n\n");
		getc(stdin); 
		getc(stdin);
		//main();//Volta ao menu
		
	} else {
		printf("\nApelido ok!!\n\n");
		getc(stdin);
		getc(stdin);
		jogo();//CHAMA JOGO
	}
}
