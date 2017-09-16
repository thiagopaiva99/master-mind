#include "functions.h"

char sort( char * string_original )//PEGANDO PONTEIRO DE J_CORRETO PARA PREENCHER COM OS DADOS ALEATORIOS.
{
    char s_resultado;//Variavel que recebe ponteiro.
    int s_x=0;//Variaveis auxiliares para laços.
    srand((unsigned)time(NULL)); //Seed da rand para deixar os numeros mais aleatorios.

    while(s_x<4) {//Laço para gerar os numeros aleatorios sem se repetir
        if(s_x==0){
            string_original[s_x]=(1 + ( rand() % 6 ));// Gera numero random
            s_x++;
        }

        if(s_x==1){
            string_original[s_x]=(1 + ( rand() % 6 ));// Gera numero random
            if (string_original[s_x] != string_original[s_x-1]){//Caso diferente do vetor anterior permite que ele continue incrementando
                s_x++;
            }
        }

        if(s_x==2){
            string_original[s_x]=(1 + ( rand() % 6 ));// Gera numero random
            if ( string_original[s_x] != string_original[s_x-2] &&  string_original[s_x] != string_original[s_x-1] ){//Caso diferente dos vetores anteriores permite que ele continue incrementando
                s_x++;
            }
        }
        if(s_x==3){
            string_original[s_x]=(1 + ( rand() % 6 ));// Gera numero random
            if (string_original[s_x] != string_original[s_x-3] &&  string_original[s_x] != string_original[s_x-2] && string_original[s_x] != string_original[s_x-1] ){//Caso diferente dos vetores anteriores permite que ele continue incrementando
                s_x++;
            }
        }
   }

   for( s_x = 0; s_x != 4; s_x++ ) {//Laço para trocar o inteiro por um caracter.
    if( string_original [ s_x ] == 1 ) string_original [ s_x ] = 'L';
    if( string_original [ s_x ] == 2 ) string_original [ s_x ] = 'C';
    if( string_original [ s_x ] == 3 ) string_original [ s_x ] = 'A';
    if( string_original [ s_x ] == 4 ) string_original [ s_x ] = 'V';
    if(string_original[s_x]==5) string_original[s_x]='R';
    if(string_original[s_x]==6) string_original[s_x]='M';
   }
}
