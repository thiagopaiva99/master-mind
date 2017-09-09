#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "prot_func.h"

//Funcao retorna primeira letra maiuscula
void Up(char *pUp){
  int i;
  for (i=0; pUp[i]!='\0'; i++){
    pUp[i] = tolower(pUp[i]);
  }
  pUp[0] = toupper(pUp[0]);
}
