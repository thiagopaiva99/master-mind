#include "prot_func.h"

//FUNCAO PARA ABERTURA DO ARQUIVO
void abrir(char tipo[3]){
	//FILE *bd;
	//char *dataBase = "base.txt";

	if((bd=fopen(dataBase, tipo))==NULL){
		printf("\n O arquivo nao pode ser aberto!\n");
		exit(1);
	}
}
