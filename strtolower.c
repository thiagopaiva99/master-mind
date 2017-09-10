#include "functions.h"

void strtolower(char *to_lower){
  int i;
  for ( i = 0; to_lower[ i ] != '\0'; i++ ) to_lower[ i ] = tolower( to_lower[ i ] );
}
