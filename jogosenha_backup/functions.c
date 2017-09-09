#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "prot_func.h"

//FUNCAO PARA ABERTURA DO ARQUIVO
/*void abrir(char tipo[3]){
	
	FILE *bd;
	char *dataBase = "DB_jogosenha.txt";
	
	if((bd=fopen(dataBase, tipo))==NULL){
		printf("\n O arquivo nao pode ser aberto!\n");
		exit(1);
	}
}
*/
//CADASTRO DO JOGADOR
void novo_jogador(void){
	char apelido[20], nome[30], idade[2], jogador[80];
	int cut;
	FILE *bd;
	
gets(nome);
	system("clear");	
        printf("## CADASTRO DE JOGADOR ##\n");
        printf("-------------------------\n");
        printf("\nApelido:"); 
	gets(apelido);
	//Low(apelido);
        printf("\nNome:"); 
	gets(nome);
	//Low(nome);        
	printf("\nIdade:"); 
	gets(idade);
        //aqui transforma palavra maiuscula
        
 	//up(apelido);
	//up(nome);
	
	strcpy(jogador, " ");
	strcat(jogador, apelido);
	strcat(jogador, ":");
	strcat(jogador, nome);
	strcat(jogador, ":");
	strcat(jogador, idade);
	cut = strlen(apelido)+strlen(nome)+strlen(idade)+3;
	jogador[cut]='\0'; 	

 	bd=fopen("DB_jogosenha.txt","a");
 	//fseek(bd,0L, SEEK_END);
 	//INSERE OS DADOS NO ARQUIVO
        fprintf(bd, "%s\n",jogador);
	printf("\n\n%s\n\n",jogador);
        printf("\n Cadastro Efetuado\n\n\n");
	getc(stdin); getc(stdin);
	fclose(bd);
}

//CONSULTA NO BANCO DE DADOS
int consulta_apelido(char apelido[15]){
    	
    	FILE *bd;
    	int conf=1;
    	char linha[50];
	//abrir("r");//Abre o arquivo modo leitura
    	system("clear");

    	while (fgets(linha,sizeof(linha),bd)!=NULL)
    	
    	if (strstr(linha,apelido)!=NULL){
        fclose(bd);
        return conf;
        }
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
	} else {
		printf("\nApelido ok!!\n\n");
		getc(stdin); getc(stdin);
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

