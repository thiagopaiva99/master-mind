#include "functions.h"

//CONSULTA NO BANCO DE DADOS
int consulta_apelido( char apelido[ 15 ] ){//char apelido[15]
	FILE *bd;

	char *dataBase = "players.txt";
	char linha[50];

	int existe = 1;

	if( ( bd = fopen( dataBase, "r" ) ) == NULL ){
		printf("\nNão foi possivel abrir o arquivo\n");
		exit(1);
	}

	system("clear");

    while ( fgets( linha, sizeof( linha ), bd ) != NULL )
    	if ( strstr( linha, apelido ) != NULL ){
            fclose( bd );
            return existe;
    }
}
