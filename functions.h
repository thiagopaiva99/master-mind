#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//FUNCOES
void jogar(void);
void novo_jogador(void);
int jogo();
char sort(char *s_correto);
void perfil(void);
void ranking(void);
void comojogar(void);
int consulta_apelido(char *apelido);
void strtolower(char *to_lower);
void strtoupper(char *to_upper);
void sair(void);
void abrir(char *tipo);

// main menu functions
void perfil();
void ranking();
void comojogar();
void sair();
void choise(char op);
