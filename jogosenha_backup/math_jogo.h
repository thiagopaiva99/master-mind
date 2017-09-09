#include "Sortear.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "prot_func.h"

//int Jogar()//EDITADO
int jogo()
{
int j_c=0,j_l=0,j_ganhar=0,j_jogadas=0,j_l2=0,j_c2=0,j_aux=0,j_dicas=0;//VARIAVEIS
char j_correto[4]; //VETOR COM AS RESPOSTAS CORRETAS DO JOGO.
char j_opcao;// VARIAVEL PARA SELEÇÃO DO USUARIO.
char j_jogo[10][8];//MATRIX PARA O JOGO.
Sortear(&j_correto[0]);//CHAMA FUNÇÃO SORTEAR DANDO PONTEIRO PARA O J_CORRETO
for(j_l2=0;j_l2!=10;j_l2++)//INICIO LAÇO PARA COLOCAR ESPAÇOS NOS CAMPOS.
{
   for(j_c2=0;j_c2!=8;j_c2++)
    {
        if(j_c2<=3)
        {
        j_jogo[j_l2][j_c2]=' ';
        }
        else
        {
        j_jogo[j_l2][j_c2]=' ';
        }
    }
}  //FIM DO LAÇO PARA COLOCAR ESPAÇOS NOS CAMPOS.


     for(j_jogadas=0;j_jogadas<10;j_jogadas++) // LAÇO PARA PERCORRER AS LINHAS
        {

                for(j_dicas=0;j_dicas<4;j_dicas++) // LAÇO PARA PERCORRER COLUNAS
                {
                        system("clear"); // CARACTERES ESPECIAIS EM NUMEROS PARA DEIXAR O JOGO COM UMA INTERFACE MAIS ATRATIVA.
                        printf("\n                      %c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
                        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cMASTERMIND%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185,204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
                        printf("\n%c       %c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c        %c",186,201,205,205,205,205,205,205,205,205,205,205,187,200,205,205,205,205,203,205,205,205,205,205,188,201,205,205,205,205,205,187,186);
                        printf("\n%c%c%c%c%c%c%c%c%cTENTATIVAS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cDICAS%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,185,204,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,185,204,205,205,205,205,205,205,205,205,185);
                        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,202,205,205,205,205,205,205,205,205,185);


                    for(j_l=0;j_l!=10;j_l++)//LAÇO PARA IMPRIMIR NA TELA (LINHAS)
                    {
                       printf("\n");
                        printf("%c%i",186,j_l+1);

                            for(j_c=0;j_c!=8;j_c++)//LAÇO PARA IMPRIMIR NA TELA (COLUNAS)
                                {
                                        if(j_l==9) //IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                                        {
                                                    if(j_c==7)//IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                                                    {
                                                    printf(" [%c]  %c",j_jogo[j_l][j_c],186);
                                                    }
                                                    if(j_c==4)//IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                                                    {
                                                    printf("    %c    [%c] ",186,j_jogo[j_l][j_c]);
                                                    }
                                                    if(j_c!=4 && j_c!=7)//IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                                                    {
                                                    printf(" [%c] ",j_jogo[j_l][j_c]);
                                                    }
                                        }
                                        else
                                        {
                                                if(j_c==7)//IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                                                {
                                                printf("  [%c]  %c",j_jogo[j_l][j_c],186);
                                                }
                                                if(j_c==4)//IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                                                    {
                                                        printf("     %c    [%c]",186,j_jogo[j_l][j_c]);
                                                    }
                                                    if(j_c!=4 && j_c!=7)//IF APENAS PARA IMPRIMIR ORGANIZADAMENTE OS DADOS
                                                    {
                                                        printf("  [%c]",j_jogo[j_l][j_c]);
                                                    }
                                        }


                                }
                    }
                        //MAIS CARACTERES PARA DEIXAR MAIS ATRATIVO COM AS INFORMAÇÕES DO JOGO.
                        printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
                        printf("\n\n P - COR CORRETA NA CASA CORRETA   B - COR CORRETA NA CASA ERRADA    ");
                        printf("\n\n Faca a sua escolha de 4 cores dentre:");
                        printf("\n L - Laranja");
                        printf("   C - Cinza");
                        printf("   A - Azul");
                        printf("   V - Vermelho");
                        printf("   R - Roxo");
                        printf("   M - Marrom");



                            //LAÇO PARA CAPUTRAR OPÇÕES DO USUARIO, TENDO CERTEZA QUE ELE DIGITOU SOMENTE AS LETRAS PERMITIDAS E APENAS PEGA 1 CARACTER POR VEZ.
                           while(j_jogo[j_jogadas][j_dicas]!='L' && j_jogo[j_jogadas][j_dicas]!='C' && j_jogo[j_jogadas][j_dicas]!='A' && j_jogo[j_jogadas][j_dicas]!='V' && j_jogo[j_jogadas][j_dicas]!='R' && j_jogo[j_jogadas][j_dicas]!='M' )
                            {
                            printf("\n Digite Apenas as Cores Disponiveis");
                            printf("\n Digite a %i cor desejada :",j_dicas+1);
                            scanf("%1c",&j_opcao);
                            fflush(stdin);
                            j_opcao =toupper(j_opcao);//CASO A LETRA DIGITADA FOR MINUSCULA ESSA FUNÇÃO A TRANSFORMA EM MAISCULA.
                            if(j_opcao=='L' || j_opcao=='C' || j_opcao=='A' || j_opcao=='V' || j_opcao=='R' || j_opcao=='M'){
                            j_jogo[j_jogadas][j_dicas]=j_opcao;
                               }
                            j_opcao=' ';
                            }



                                            for(j_c=0;j_c!=4;j_c++)//LAÇO PARA A ANALIZE E PREENCHIMENTO DAS DICAS.
                                            {

                                                                if(j_c==0)//PASSANDO A ESCOLHA 1 EM CADA CASA.
                                                                {
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[0])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='P';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[1])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[2])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[3])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                }
                                                                if(j_c==1)//PASSANDO A ESCOLHA 2 EM CADA CASA.
                                                                {
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[0])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[1])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='P';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[2])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[3])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                }
                                                                if(j_c==2)//PASSANDO A ESCOLHA 3 EM CADA CASA.
                                                                {
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[0])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[1])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[2])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='P';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[3])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                }
                                                                if(j_c==3)//PASSANDO A ESCOLHA 4 EM CADA CASA.
                                                                {
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[0])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[1])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[2])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='B';
                                                                    }
                                                                    if(j_jogo[j_jogadas][j_c]==j_correto[3])
                                                                    {
                                                                        j_jogo[j_jogadas][j_c+4]='P';
                                                                    }
                                                                }
                                            }
                }
                //PARA VERIFICAR SE GANHOU O JOGO E SE GANHOU IMPRIMI NA TELA OS DESENHOS RETORNA O NUMERO DE JOGADAS E FECHA O LAÇO DO JOGO.
                if(j_jogo[j_jogadas][4]=='P' && j_jogo[j_jogadas][5]=='P' && j_jogo[j_jogadas][6]=='P' & j_jogo[j_jogadas][7]=='P')
                {
 system("clear");
 printf("                           vB@@@B@B@@@B@B@B@Br\n");
 printf("                     B@B@B@@@B@B@B@@@B@B@@@B@B@B@B@\n");
 printf("                     @BG ,.LB@B@@@B@B@B@@@B@Bv., MB\n");
 printf("                      @B    @B@B@B@B@@@B@B@B@    B@\n");
 printf("                      J@J   B@@@B@B@@@@@@@@@O   U@i\n");
 printf("                       B@F   B@B@B@B@B@B@B@@   P@B \n");
 printf("                        F@BBr@B@B@B@B@B@B@BBr@@@u\n");
 printf("                          7M@BBB@B@@@B@B@BMB@Or\n");
 printf("                               ,B@B@@@@@B.\n");
 printf("                                 .X@@BS.\n");
 printf("                                   @@@ \n");
 printf("                                   B@B\n");
 printf("                              L@OZO@B@GZO@7\n");
 printf("                              @B@B@@@B@B@B@\n");
 printf("                             @B@B@BBM@B@B@B@\n\n\n");

 printf("     B@B@B@      :@B@     @Br     @i  @B@.  .B@B.   ,B@u5B@,   7@B@     @i\n");
 printf("   :B@v   B@     @B@B,    B@@     B:  B@B    @B@   7@@:  iB@r  iB@B     B:\n");
 printf("   B@B     @     B@B@B    @B@@    @:  @B@    B@B   B@@    @B@  :@B@     @:\n");
 printf("  B@@@          i@ @B@    B@B@B   B:  B@B    @B@  i@B@    B@B: :B@B     B:\n");
 printf("  @B@B          @. B@@.   @v@B@i  @:  @B@r,,rB@B  @@@@    @B@q :@B@     @:\n");
 printf("  @@B@  B@@@B   @  @B@B   @ B@@@  B:  B@B@LYB@B@  B@B@    B@@@ :B@B     B:\n");
 printf("  @B@B   :@B@  i@  .@B@   @  @@B@ @,  @B@    @@B  @B@B    @B@M :@B@     @:\n");
 printf("  @@B@    B@B  @Y   B@B   B   @@B@B.  B@B    @B@  r@B@    B@B; :B@B     B:\n");
 printf("  rB@B    @B@  B@B@B@B@Z  @   iB@B@   @B@    B@B   B@B    @B@  ,@B@     @.\n");
 printf("   @B@   .B@B :@    i@B@  B    @B@B.  @@B    @B@   @B@   .B@B   B@@.   .B \n");
 printf("    MB@rrB@B@ @r     B@B  @     @@@:  @B@.  .@@@,   qB@..B@2    .@@B@2@B\n");
 printf("      ,uj     ,      . .  ,                  . .      :uj:         ivL.\n");
system("sleep 10");
system("clear");
j_ganhar=1;
return j_jogadas;
j_jogadas=10;





                }

        }

// CASO FECHE O LAÇO DOS 10 SEM GANHAR IRA EXIBIR O DESENHO E RETORNAR O VALOR DAS JOGADAS.
if(j_ganhar==0)
{
system("clear");
printf("                                UM0EEZ0ZEM1 \n");
printf("                             5@E@@@B@B@B@B@G@F \n");
printf("                          P@O@B@B@B@B@BBM@B@B@M@G \n");
printf("                        ,B@@@B@MBMBMMMMMBMBMBB@B@@:\n");
printf("                       O@@@@MMMMMMMMMMMBMBMMMBM@@@BM\n");
printf("                     :@@@MBMMMMMBMBMMMBMMMMMMMBMBB@B@:\n");
printf("                    .jB@MBMMMBMBMMMBMBMMMBMBMMMMMBM@@u.\n");
printf("                    @B@BBMMMMMBMBMMMMMBMMMMMBMMMMMMM@B@ \n");
printf("                    @@B@BBMMMMMBMBMBMMMBMBMBMBMBMBB@B@B \n");
printf("                    @B@@@BBMBM@B@B@BBMBB@B@B@MBMBB@B@B@ \n");
printf("                    @@B .@@BM@BBB@B@B@B@B@BBB@MBB@, B@B \n");
printf("                    @@@  B@B@Bj    L@@ML    J@@B@B  @B@  \n");
printf("                    B@B@Y 0@B@B@B@B ,@. @@B@B@B@O 7@B@B \n");
printf("                    5M@BF @BFkEEEB@@@r@B@BZZ0k5B@ LB@MF \n");
printf("                     iBLivSi      27: :v2      :kLivBi   \n");
printf("      JuJ             7:72          5B2          Uv:7             juu \n");
printf("      @@BOi            @Z          @B@B@          F@            i8@@@  \n");
printf("    7M@B@B@O         :@Bk        .@BO BB@.        uB@:         M@B@B@Mv \n");
printf("  .@B@B@B@B@BO       7B@BE.   :@G@B:   :B@G@r    0B@B7       EB@B@B@B@B@,\n");
printf("    JB@BBO@B@B@7     i@B5 1MMBF  :@     @:  5BMMF jB@r     r@B@B@OBM@B1 \n");
printf("           MNOB@B@E   G@B@,.:  @B@B  :  @@B@  :..@B@8  .N@B@BM0M  \n");
printf("              uB@B@@v  :MB@@Xr5B@@@:vB7:@B@@SrkB@BBi  vB@B@@2  \n");
printf("               .viE@B@7  7i  iZ@B@B@B@B@B@B@Zr  i7  7@B@E;v. \n");
printf("                   i:G@@; vi  .B,:@BG OB@i:@:  iL :B@G,i\n");
printf("                      ,i. B@  :@  B@u 1@B  @i  M@  i, \n");
printf("                          @M                   G@\n");
printf("                          MO, .@  B@L u@@  @. ,EB\n");
printf("                           .@:YB,:@BG GB@i.BU:@.\n");
printf("                       ivL   @B@B@B@B@B@B@@@B@   Lvi \n");
printf("                    L1uB@B,  ir:@B@@@@@B@@@:7i  .B@@21L  \n");
printf("                 SO8B@B@B:      .:.......:.      :M@B@BO8k \n");
printf("          ,B@MBB@B@@@F                               5@B@B@B@M@B, \n");
printf("         @B@B@B@B@L                                     L@B@B@B@@@ \n");
printf("         BM MB@:                                           .@@@ EB \n");
printf("           BMS                                               uMB. \n\n\n");
printf("            vBBBB          .@M@B         JBM,    Bi       GGZG@B:  \n");
printf("          .@B@..,@J       q@B:  BP       OB@BN JB@v       B@Br,i  \n");
printf("          :B@B   .        @B@   @B       S@Bi @i B7       @B@ML  \n");
printf("          :@BB :B@X       B@BBMB@O       XB@.    @r       B@B    \n");
printf("          .M@B::;Bu       @B@   @B       O@Bi    Bj       @B@r:7.\n");
printf("            iOGM0         j0X   Su       70Z,    M:       5PSGM@:\n");
printf("                                                                  \n");
printf("                                                                   \n");
printf("                                                                  \n");
printf("            S@B@B.        B@B    :B:       @@@M@B       J@@@@@P  \n");
printf("          :B@B   BP       MB@:   r@,       B@@,         1B@u  :B;\n");
printf("          .@B@   @E        ,B@F B@         @@@B:        v@BS .:@,\n");
printf("          :B@B   @O        .B@M OS         B@0          L@@@MBq  \n");
printf("          .MB@:iiBL          @B@           @@@,ri       2@BF  ,@r \n");
printf("            7MBBM            jMO           NENBBM       iOOr  .B: \n");
system("sleep 10");
system("clear");
return 11;
}
}
