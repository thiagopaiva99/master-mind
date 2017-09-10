#include "functions.h"

void strtoupper(char *to_upper){
  int i;

  for ( i = 0; to_upper[ i ] != '\0'; i++ ) to_upper[ i ] = tolower( to_upper[ i ] );

  to_upper[ 0 ] = toupper( to_upper[ 0 ] );
}
