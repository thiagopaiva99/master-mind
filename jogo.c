#include "functions.h"
#include "sort.h"

//int Jogar() ALTERADO
int jogo( char username[20] ){
    int coluna      = 0,
        linha       = 0,
        ganhar      = 0,
        jogada      = 0,
        linha2      = 0,
        coluna2     = 0,
        j_aux       = 0,
        dica        = 0;//VARIAVEIS

    FILE *db;
	char *ranking = "ranking.txt";

    char respostas[4];          // VETOR COM AS RESPOSTAS CORRETAS DO JOGO.
    char opcao;               // VARIAVEL PARA SELE��O DO USUARIO.
    char jogo[10][8];         // MATRIX PARA O JOGO.

    sort( &respostas[0] );     // CHAMA FUN��O SORTEAR DANDO PONTEIRO PARA O J_CORRETO

    for( linha2 = 0; linha2 != 10; linha2++ ){
        for( coluna2 = 0; coluna2 != 8; coluna2 ++ ){

            if ( coluna2 <= 3 ) jogo[ linha2 ][ coluna2 ] = ' ';
            else                jogo[ linha2 ][ coluna2 ] = ' ';

        }
    }  //FIM DO LA�O PARA COLOCAR ESPA�OS NOS CAMPOS.

    for( jogada = 0; jogada < 10; jogada++ ) { // LA�O PARA PERCORRER AS LINHAS
        for( dica = 0; dica < 4; dica++ ) { // LA�O PARA PERCORRER COLUNAS
            system( "clear" ); // CARACTERES ESPECIAIS EM NUMEROS PARA DEIXAR O JOGO COM UMA INTERFACE MAIS ATRATIVA.
            printf( "\n+----------------------------------------------------+" );
            printf( "\n|                      MASTERMIND                    |" );
            printf( "\n|                           |                        |" );
            printf( "\n|       TENTATIVAS          |         DICAS          |" );
            printf( "\n|                           |                        |" );
            printf( "\n|----------------------------------------------------|" );
            printf( "\n|                           |                        |" );

            for( linha = 0; linha != 10; linha++ ) { //LA�O PARA IMPRIMIR NA TELA (LINHAS)
                printf( "\n" );
                printf( "| %i", linha + 1 );

                for( coluna = 0; coluna != 8; coluna++ ) { //LA�O PARA IMPRIMIR NA TELA (COLUNAS)
                    if( linha == 9 ) { //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna == 7 )                   printf(" [%c]  |",       jogo[ linha ][ coluna ] );            //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna == 4 )                   printf("    |    [%c] ", jogo[ linha ][ coluna ] );      //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna != 4 && coluna != 7 )    printf(" [%c] ",         jogo[ linha ][ coluna ] );         //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                    } else {
                        if( coluna == 7 )                   printf("  [%c]  |",      jogo[ linha ][ coluna ] );           //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna == 4 )                   printf("     |    [%c]", jogo[ linha ][ coluna ]);      //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                        if( coluna != 4 && coluna != 7 )    printf("  [%c]",         jogo[ linha ][ coluna ]);         //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                    }
                }
            }

            //MAIS CARACTERES PARA DEIXAR MAIS ATRATIVO COM AS INFORMA��ES DO JOGO.
            printf( "\n+----------------------------------------------------+" );
            printf( "\n\n P - Cor correta na casa correta   B - Cor certa na casa errada" );
            printf( "\n\n Faca a sua escolha de 4 cores dentre:" );
            printf( "\n\n L - Laranja | C - Cinza | A - Azul | V - Vermelho | R - Roxo | M - Marrom" );

            //LA�O PARA CAPUTRAR OP��ES DO USUARIO, TENDO CERTEZA QUE ELE DIGITOU SOMENTE AS LETRAS PERMITIDAS E APENAS PEGA 1 CARACTER POR VEZ.
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

                opcao = toupper( opcao );//CASO A LETRA DIGITADA FOR MINUSCULA ESSA FUN��O A TRANSFORMA EM MAISCULA.

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

            for( coluna = 0; coluna != 4; coluna++ ) { //LA�O PARA A ANALIZE E PREENCHIMENTO DAS DICAS.
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

        //PARA VERIFICAR SE GANHOU O JOGO E SE GANHOU IMPRIMI NA TELA OS DESENHOS RETORNA O NUMERO DE JOGADAS E FECHA O LA�O DO JOGO.
        if (
                jogo[ jogada ][ 4 ] == 'P' &&
                jogo[ jogada ][ 5 ] == 'P' &&
                jogo[ jogada ][ 6 ] == 'P' &&
                jogo[ jogada ][ 7 ] == 'P'
        ){
             system("clear");

             if( ( db = fopen( ranking, "a+t" ) ) == NULL ) {
                printf("\nO arquivo nao pode ser aberto!\n");
                exit(1);
             }

             fseek( db, 0L, SEEK_END );

             //INSERE OS DADOS NO ARQUIVO
             fprintf( db, "%s:%d\n", username, jogada );

             fclose( db );
             system( "clear" );

             printf( "+-----------------------+\n" );
             printf( "|                       |\n" );
             printf( "|        YOU WIN        |\n" );
             printf( "|                       |\n" );
             printf( "+-----------------------+\n" );

             system( "mpg321 -g 80 win.mp3 --quiet" );

             ganhar = 1;
             return jogada;
             jogada = 10;
        }

    }

    // CASO FECHE O LA�O DOS 10 SEM GANHAR IRA EXIBIR O DESENHO E RETORNAR O VALOR DAS JOGADAS.
    if( ganhar == 0 ) {
        system("clear");

        printf( "+-----------------------+\n" );
        printf( "|                       |\n" );
        printf( "|         YOU LOSE      |\n" );
        printf( "|                       |\n" );
        printf( "+-----------------------+\n" );

        system( "mpg321 -g 80 lose.mp3 --quiet" );

        system("sleep 2");
        system("clear");
        return 11;
    }
}
