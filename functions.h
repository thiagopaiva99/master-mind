#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//FUNCOES

// funcao de jogar
void jogar(void);

// funcao de novo jogador
void novo_jogador(void);

// funcao que chama o jogo
int jogo( char username[20] );

// funcao que sorteia os chars
char sort(char *s_correto);

// funcao do perfil
void perfil(void);

// funcao do ranking
void ranking(void);

// funcao de como jogar
void comojogar(void);

// funcao que consulta o apelido
int consulta_apelido(char *apelido);

// funcao para letras minusculas
void strtolower(char *to_lower);

// funcao para letras maiusculas
void strtoupper(char *to_upper);

// funcao para sair
void sair(void);

// funcao para abri arquivos
void abrir(char *tipo);

// funcao para escolher a opção do menu
void choise(char op);
