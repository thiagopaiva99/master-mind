#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//#include <locale.h>
#include "prot_func.h"


struct jogador
{
	char apelido[15];
	char nome[20];
	char idade[2];
} jog;

FILE *bd;
char *dataBase = "base.txt";


//PROGRAMA
void main(void)
{
    //setlocale(LC_ALL, "Portuguese");//para acentuação
	char opcao[2], op;
	do{
		do{
			system("clear");
			printf("#---------------------------#\n");
			printf("#			    #\n");
			printf("#	JOGO DA SENHA	    #\n");
			printf("#                           #\n");
			printf("#---------------------------#\n\n");
			printf(" > Escolha uma Opção\n");
			printf("\n <N> - Novo jogador");
			printf("\n <J> - Jogar");
			printf("\n <P> - Perfil");
			printf("\n <R> - Ranking");
			printf("\n <C> - Como Jogar");
			printf("\n <S> - Sair");
			printf("\n\n >> Opção:");
			scanf("%s",opcao);//captura do teclado
			op=tolower(*opcao);//op recebe a opcao em minusculo
		} while(!strchr("njprcs", op));//1do

		switch(op){
			case 'n' : novo_jogador(); break;
			case 'j' : jogar(); break;
			case 'p' : perfil(); break;
			case 'r' : ranking(); break;
			case 'c' : comojogar(); break;
			case 's' : sair(); break;
		}//switch
	}while(1);

}//main

//FUNCAO PARA ABERTURA DO ARQUIVO

void abrir(char tipo[3]){
	
	if((bd=fopen(dataBase, tipo))==NULL){
		printf("\n O arquivo nao pode ser aberto!\n");
		exit(1);
	}
}


//CONSULTA NO BANCO DE DADOS
int consulta_apelido(char apelido[15]){
    	int conf=1;
    	char linha[50];

    	abrir("r");//Abre o arquivo modo leitura
    	system("clear");

    	while (fgets(linha,sizeof(linha),bd)!=NULL)
    	if (strstr(linha,apelido)!=NULL){
            	fclose(bd);
            	return conf;
        }
}

//CADASTRO DO JOGADOR
void novo_jogador(void){
	
	system("clear");
	abrir("a+t");
	fseek(bd,0L, SEEK_END);

	printf("## CADASTRO DE JOGADOR ##\n");
	printf("-------------------------\n");
	//setbuf(stdin,NULL);	
	printf("\nApelido:"); scanf("%s",jog.apelido);
	Up(jog.apelido);	
	printf("\nNome:"); scanf("%s",jog.nome);
	Up(jog.nome);
	printf("\nIdade:"); scanf("%s",jog.idade);

	//INSERE OS DADOS NO ARQUIVO
	fprintf(bd, "%s:%s:%s\n",jog.apelido,jog.nome,jog.idade);
	printf("\n Cadastro Efetuado\n\n\n");

	fclose(bd);
}


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
		getc(stdin); getc(stdin);
		exit(1);//COLOCADO DEPOIS	
	} else {
		printf("\nApelido ok!!\n\n");
		getc(stdin); getc(stdin);
		jogo();//CHAMA JOGO
	}
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


