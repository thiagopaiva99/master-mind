#include "functions.h"

char sort( char * string_original )//PEGANDO PONTEIRO DE J_CORRETO PARA PREENCHER COM OS DADOS ALEATORIOS.
{
    int x = 0;//Variaveis auxiliares para laços.
    srand((unsigned)time(NULL)); //Seed da rand para deixar os numeros mais aleatorios.

    while( x < 4 ) {//Laço para gerar os numeros aleatorios sem se repetir
        if ( x == 0 ){
            string_original [ x ] = ( 1 + ( rand() % 6 ) );// Gera numero random
            x++;
        }

        if ( x == 1 ) {
            string_original [ x ] = ( 1 + ( rand() % 6 ) );// Gera numero random

            if ( string_original [ x ] != string_original [ x - 1 ] ) x++; //Caso diferente do vetor anterior permite que ele continue incrementando
        }

        if ( x == 2 ) {
            string_original [ x ] = ( 1 + ( rand() % 6 ) );// Gera numero random

            if ( string_original [ x ] != string_original [ x - 2 ] && string_original [ x ] != string_original [ x - 1 ] ) x++;//Caso diferente dos vetores anteriores permite que ele continue incrementando
        }

        if ( x == 3 ) {
            string_original [ x ] = ( 1 + ( rand() % 6 ) );// Gera numero random

            if ( string_original [ x ] != string_original [ x - 3 ] && string_original [ x ] != string_original [ x - 2 ] && string_original [ x ] != string_original [ x - 1 ] ) x++;//Caso diferente dos vetores anteriores permite que ele continue incrementando
        }
   }

   for( x = 0; x != 4; x++ ) {//Laço para trocar o inteiro por um caracter.
    if( string_original [ x ] == 1 ) string_original [ x ] = 'L';
    if( string_original [ x ] == 2 ) string_original [ x ] = 'C';
    if( string_original [ x ] == 3 ) string_original [ x ] = 'A';
    if( string_original [ x ] == 4 ) string_original [ x ] = 'V';
    if( string_original [ x ] == 5 ) string_original [ x ] = 'R';
    if( string_original [ x ] == 6 ) string_original [ x ] = 'M';
   }
}
