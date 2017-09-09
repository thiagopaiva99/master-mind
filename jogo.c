#include "prot_func.h"
#include "sort.h"

//int Jogar() ALTERADO
int main(){
    int j_c         = 0,
        j_l         = 0,
        j_ganhar    = 0,
        j_jogadas   = 0,
        j_l2        = 0,
        j_c2        = 0,
        j_aux       = 0,
        j_dicas     = 0;//VARIAVEIS

    char j_correto[4];          // VETOR COM AS RESPOSTAS CORRETAS DO JOGO.
    char j_opcao;               // VARIAVEL PARA SELEÇÃO DO USUARIO.
    char j_jogo[10][8];         // MATRIX PARA O JOGO.

    sort(&j_correto[0]);     // CHAMA FUNÇÃO SORTEAR DANDO PONTEIRO PARA O J_CORRETO

    for( j_l2 = 0; j_l2 != 10; j_l2++ ){
        for( j_c2 = 0; j_c2 != 8; j_c2 ++ ){

            if ( j_c2 <= 3 ) j_jogo[j_l2][j_c2] = ' ';
            else j_jogo[j_l2][j_c2] = ' ';

        }
    }  //FIM DO LAÇO PARA COLOCAR ESPAÇOS NOS CAMPOS.

    for( j_jogadas = 0; j_jogadas < 10; j_jogadas++ ) { // LAÇO PARA PERCORRER AS LINHAS
        for( j_dicas = 0; j_dicas < 4; j_dicas++ ) { // LAÇO PARA PERCORRER COLUNAS
            system( "clear" ); // CARACTERES ESPECIAIS EM NUMEROS PARA DEIXAR O JOGO COM UMA INTERFACE MAIS ATRATIVA.
            printf( "\n+----------------------------------------------------+" );
            printf( "\n|                      MASTERMIND                    |" );
            printf( "\n|                           |                        |" );
            printf( "\n|       TENTATIVAS          |         DICAS          |" );
            printf( "\n|                                                    |" );

            for( j_l = 0; j_l != 10; j_l++ ) { //LAÇO PARA IMPRIMIR NA TELA (LINHAS)
                printf( "\n" );
                printf( "| %i", j_l + 1 );

                for( j_c = 0; j_c != 8; j_c++ ) { //LAÇO PARA IMPRIMIR NA TELA (COLUNAS)
                    if( j_l == 9 ) { //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( j_c == 7 )              printf(" [%c]  |",j_jogo[j_l][j_c],186);            //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( j_c == 4 )              printf("    |    [ ] ",186,j_jogo[j_l][j_c]);      //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( j_c != 4 && j_c != 7 )  printf(" [%c] ",j_jogo[j_l][j_c]);         //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                    } else {
                        if( j_c == 7 )              printf("  [%c]  |",j_jogo[j_l][j_c],186);           //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( j_c == 4 )              printf("     |    [ ]",j_jogo[j_l][j_c]);      //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( j_c != 4 && j_c != 7 )  printf("  [%c]",j_jogo[j_l][j_c]);         //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                    }
                }
            }

            //MAIS CARACTERES PARA DEIXAR MAIS ATRATIVO COM AS INFORMAÇÕES DO JOGO.
            printf( "\n+----------------------------------------------------+" );
            printf( "\n\n P - Cor correta na casa correta   B - Cor certa na casa errada" );
            printf( "\n\n Faca a sua escolha de 4 cores dentre:" );
            printf( "\n\n L - Laranja | C - Cinza | A - Azul | V - Vermelho | R - Roxo | M - Marrom" );

            //LAÇO PARA CAPUTRAR OPÇÕES DO USUARIO, TENDO CERTEZA QUE ELE DIGITOU SOMENTE AS LETRAS PERMITIDAS E APENAS PEGA 1 CARACTER POR VEZ.
            while(
                    j_jogo[ j_jogadas ][ j_dicas ] != 'L' &&
                    j_jogo[ j_jogadas ][ j_dicas ] != 'C' &&
                    j_jogo[ j_jogadas ][ j_dicas ] != 'A' &&
                    j_jogo[ j_jogadas ][ j_dicas ] != 'V' &&
                    j_jogo[ j_jogadas ][ j_dicas ] != 'R' &&
                    j_jogo[ j_jogadas ][ j_dicas ] != 'M'
            ){
                printf( "\n Digite Apenas as Cores Disponiveis" );
                printf( "\n Digite a %i cor desejada :",j_dicas+1 );
                scanf( "%1c", &j_opcao );
                fflush(stdin);

                j_opcao = toupper(j_opcao);//CASO A LETRA DIGITADA FOR MINUSCULA ESSA FUNÇÃO A TRANSFORMA EM MAISCULA.

                if(
                    j_opcao == 'L' ||
                    j_opcao == 'C' ||
                    j_opcao == 'A' ||
                    j_opcao == 'V' ||
                    j_opcao == 'R' ||
                    j_opcao == 'M'
                )
                    j_jogo[ j_jogadas ][ j_dicas ] = j_opcao;

                j_opcao = ' ';
            }

            for( j_c = 0; j_c != 4; j_c++ ) { //LAÇO PARA A ANALIZE E PREENCHIMENTO DAS DICAS.
                if(j_c==0) { //PASSANDO A ESCOLHA 1 EM CADA CASA.
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 0 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'P';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 1 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 2 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 3 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                }

                if(j_c==1) { //PASSANDO A ESCOLHA 2 EM CADA CASA.
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 0 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 1 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'P';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 2 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 3 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                }

                if(j_c==2) { //PASSANDO A ESCOLHA 3 EM CADA CASA.
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 0 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 1 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 2 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'P';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 3 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                }

                if(j_c==3) { //PASSANDO A ESCOLHA 4 EM CADA CASA.
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 0 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 1 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 2 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'B';
                    if ( j_jogo[ j_jogadas ][ j_c ] == j_correto[ 3 ] ) j_jogo[ j_jogadas ][ j_c + 4 ] = 'P';
                }
            }
        }

        //PARA VERIFICAR SE GANHOU O JOGO E SE GANHOU IMPRIMI NA TELA OS DESENHOS RETORNA O NUMERO DE JOGADAS E FECHA O LAÇO DO JOGO.
        if (
                j_jogo[ j_jogadas ][ 4 ] == 'P' &&
                j_jogo[ j_jogadas ][ 5 ] == 'P' &&
                j_jogo[ j_jogadas ][ 6 ] == 'P' &&
                j_jogo[ j_jogadas ][ 7 ] == 'P'
        ){
             system("clear");

             system("sleep 10");
             system("clear");

             j_ganhar=1;
             return j_jogadas;
             j_jogadas=10;
        }

    }

    // CASO FECHE O LAÇO DOS 10 SEM GANHAR IRA EXIBIR O DESENHO E RETORNAR O VALOR DAS JOGADAS.
    if(j_ganhar==0) {
        system("clear");

        system("sleep 10");
        system("clear");
        return 11;
    }
}
