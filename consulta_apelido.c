#include "functions.h"

//CONSULTA NO BANCO DE DADOS
int consulta_apelido(char apelido[15]){//char apelido[15]

	FILE *bd;
	char *dataBase = "players.txt";
	int conf=1;
    	char linha[50];

	if((bd=fopen(dataBase, "r"))==NULL){
		printf("\n O arquivo nao pode ser aberto!\n");
		exit(1);
	}

	system("clear");
    	while (fgets(linha,sizeof(linha),bd)!=NULL)
    	if (strstr(linha,apelido)!=NULL){
            	fclose(bd);
            	return conf;
        }
}
