#include "functions.h"

void abrir( char tipo [ 3 ] ){
	if( ( bd = fopen( dataBase, tipo ) )== NULL ){
		printf("\nNão foi possivel abrir o arquivo\n");
		exit(1);
	}
}
