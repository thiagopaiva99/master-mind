#include "prot_func.h"
#include "sort.h"

//int Jogar() ALTERADO
int main(){
    int coluna      = 0,
        linha       = 0,
        ganhar      = 0,
        jogada      = 0,
        j_l2        = 0,
        j_c2        = 0,
        j_aux       = 0,
        dica        = 0;//VARIAVEIS

    char respostas[4];          // VETOR COM AS RESPOSTAS CORRETAS DO JOGO.
    char opcao;               // VARIAVEL PARA SELEÇÃO DO USUARIO.
    char jogo[10][8];         // MATRIX PARA O JOGO.

    sort( &respostas[0] );     // CHAMA FUNÇÃO SORTEAR DANDO PONTEIRO PARA O J_CORRETO

    for( j_l2 = 0; j_l2 != 10; j_l2++ ){
        for( j_c2 = 0; j_c2 != 8; j_c2 ++ ){

            if ( j_c2 <= 3 ) jogo[j_l2][j_c2] = ' ';
            else jogo[j_l2][j_c2] = ' ';

        }
    }  //FIM DO LAÇO PARA COLOCAR ESPAÇOS NOS CAMPOS.

    for( jogada = 0; jogada < 10; jogada++ ) { // LAÇO PARA PERCORRER AS LINHAS
        for( dica = 0; dica < 4; dica++ ) { // LAÇO PARA PERCORRER COLUNAS
            system( "clear" ); // CARACTERES ESPECIAIS EM NUMEROS PARA DEIXAR O JOGO COM UMA INTERFACE MAIS ATRATIVA.
            printf( "\n+----------------------------------------------------+" );
            printf( "\n|                      MASTERMIND                    |" );
            printf( "\n|                           |                        |" );
            printf( "\n|       TENTATIVAS          |         DICAS          |" );
            printf( "\n|                                                    |" );

            for( linha = 0; linha != 10; linha++ ) { //LAÇO PARA IMPRIMIR NA TELA (LINHAS)
                printf( "\n" );
                printf( "| %i", linha + 1 );

                for( coluna = 0; coluna != 8; coluna++ ) { //LAÇO PARA IMPRIMIR NA TELA (COLUNAS)
                    if( linha == 9 ) { //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna == 7 )                   printf(" [%c]  |",       jogo[ linha ][ coluna ] );            //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna == 4 )                   printf("    |    [%c] ", jogo[ linha ][ coluna ] );      //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna != 4 && coluna != 7 )    printf(" [%c] ",         jogo[ linha ][ coluna ] );         //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                    } else {
                        if( coluna == 7 )                   printf("  [%c]  |",      jogo[ linha ][ coluna ] );           //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna == 4 )                   printf("     |    [ ]",  jogo[ linha ][ coluna ]);      //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna != 4 && coluna != 7 )    printf("  [%c]",         jogo[ linha ][ coluna ]);         //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
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
                    jogo[ jogada ][ dica ] != 'L' &&
                    jogo[ jogada ][ dica ] != 'C' &&
                    jogo[ jogada ][ dica ] != 'A' &&
                    jogo[ jogada ][ dica ] != 'V' &&
                    jogo[ jogada ][ dica ] != 'R' &&
                    jogo[ jogada ][ dica ] != 'M'
            ){
                printf( "\n Digite Apenas as Cores Disponiveis" );
                printf( "\n Digite a %i cor desejada :", dica + 1 );
                scanf( "%1c", &opcao );
                fflush(stdin);

                opcao = toupper( opcao );//CASO A LETRA DIGITADA FOR MINUSCULA ESSA FUNÇÃO A TRANSFORMA EM MAISCULA.

                if(
                    opcao == 'L' ||
                    opcao == 'C' ||
                    opcao == 'A' ||
                    opcao == 'V' ||
                    opcao == 'R' ||
                    opcao == 'M'
                )
                    jogo[ jogada ][ dica ] = opcao;

                opcao = ' ';
            }

            for( coluna = 0; coluna != 4; coluna++ ) { //LAÇO PARA A ANALIZE E PREENCHIMENTO DAS DICAS.
                if( coluna == 0 ) { //PASSANDO A ESCOLHA 1 EM CADA CASA.
                    if ( jogo[ jogada ][ coluna ] == respostas[ 0 ] ) jogo[ jogada ][ coluna + 4 ] = 'P';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 1 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 2 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 3 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                }

                if( coluna == 1 ) { //PASSANDO A ESCOLHA 2 EM CADA CASA.
                    if ( jogo[ jogada ][ coluna ] == respostas[ 0 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 1 ] ) jogo[ jogada ][ coluna + 4 ] = 'P';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 2 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 3 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                }

                if( coluna == 2 ) { //PASSANDO A ESCOLHA 3 EM CADA CASA.
                    if ( jogo[ jogada ][ coluna ] == respostas[ 0 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 1 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 2 ] ) jogo[ jogada ][ coluna + 4 ] = 'P';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 3 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                }

                if( coluna == 3 ) { //PASSANDO A ESCOLHA 4 EM CADA CASA.
                    if ( jogo[ jogada ][ coluna ] == respostas[ 0 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 1 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 2 ] ) jogo[ jogada ][ coluna + 4 ] = 'B';
                    if ( jogo[ jogada ][ coluna ] == respostas[ 3 ] ) jogo[ jogada ][ coluna + 4 ] = 'P';
                }
            }
        }

        //PARA VERIFICAR SE GANHOU O JOGO E SE GANHOU IMPRIMI NA TELA OS DESENHOS RETORNA O NUMERO DE JOGADAS E FECHA O LAÇO DO JOGO.
        if (
                jogo[ jogada ][ 4 ] == 'P' &&
                jogo[ jogada ][ 5 ] == 'P' &&
                jogo[ jogada ][ 6 ] == 'P' &&
                jogo[ jogada ][ 7 ] == 'P'
        ){
             system("clear");

             system("sleep 10");
             system("clear");

             ganhar = 1;
             return jogada;
             jogada = 10;
        }

    }

    // CASO FECHE O LAÇO DOS 10 SEM GANHAR IRA EXIBIR O DESENHO E RETORNAR O VALOR DAS JOGADAS.
    if( ganhar == 0 ) {
        system("clear");

        system("sleep 10");
        system("clear");
        return 11;
    }
}
