#include "functions.h"

void abrir(char tipo[3]){
	if((bd=fopen(dataBase, tipo))==NULL){
		printf("\n O arquivo nao pode ser aberto!\n");
		exit(1);
	}
}
