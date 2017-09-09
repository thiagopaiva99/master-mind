#include "prot_func.h"

//Funcao retorna palavra minuscula
void Low(char *pLow){
  int i;
  for (i=0; pLow[i]!='\0'; i++){
    pLow[i] = tolower(pLow[i]);
  }
}
