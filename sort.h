#include "functions.h"

char sort(char *s_correto)//PEGANDO PONTEIRO DE J_CORRETO PARA PREENCHER COM OS DADOS ALEATORIOS.
{

char s_resultado;//Variavel que recebe ponteiro.
int s_x=0;//Variaveis auxiliares para laços.
srand((unsigned)time(NULL)); //Seed da rand para deixar os numeros mais aleatorios.

    while(s_x<4)//Laço para gerar os numeros aleatorios sem se repetir
    {
                if(s_x==0)
                {
                s_correto[s_x]=(1 + ( rand() % 6 ));// Gera numero random
                s_x++;
                }

                if(s_x==1)
                {
                s_correto[s_x]=(1 + ( rand() % 6 ));// Gera numero random
                if (s_correto[s_x] != s_correto[s_x-1])//Caso diferente do vetor anterior permite que ele continue incrementando
                {
                s_x++;
                }
                }

                if(s_x==2){
                s_correto[s_x]=(1 + ( rand() % 6 ));// Gera numero random
                if ( s_correto[s_x] != s_correto[s_x-2] &&  s_correto[s_x] != s_correto[s_x-1] )//Caso diferente dos vetores anteriores permite que ele continue incrementando
                {
                s_x++;
                }
                }
                if(s_x==3){
                s_correto[s_x]=(1 + ( rand() % 6 ));// Gera numero random
                if (s_correto[s_x] != s_correto[s_x-3] &&  s_correto[s_x] != s_correto[s_x-2] && s_correto[s_x] != s_correto[s_x-1] )//Caso diferente dos vetores anteriores permite que ele continue incrementando
                {
                s_x++;
                }
                }

    }
       for(s_x=0;s_x!=4;s_x++)//Laço para trocar o inteiro por um caracter.
        {
        if(s_correto[s_x]==1){
           s_correto[s_x]='L';
        }
        if(s_correto[s_x]==2){
           s_correto[s_x]='C';
        }
        if(s_correto[s_x]==3){
           s_correto[s_x]='A';
        }
        if(s_correto[s_x]==4){
           s_correto[s_x]='V';
        }
        if(s_correto[s_x]==5){
           s_correto[s_x]='R';
        }
        if(s_correto[s_x]==6){
           s_correto[s_x]='M';
        }
       }
//return ;//NÃO PRECISA RETORNAR NADA POIS OS DADOS ESTÃO ESCRITOS NO PONTEIRO PASSADO POR PARAMETRO.

}
