#include "prot_func.h"

struct jogador
{
	char apelido[15];
	char nome[20];
	char idade[2];
} jog;

//CADASTRO DO JOGADOR
void novo_jogador(void){
	
	FILE *bd;
	char *dataBase = "base.txt";
	
	if((bd=fopen(dataBase, "a+t"))==NULL){
		printf("\n O arquivo nao pode ser aberto!\n");
		exit(1);
	}	

	system("clear");	
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
