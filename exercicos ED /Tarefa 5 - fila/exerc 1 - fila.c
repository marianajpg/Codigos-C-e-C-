/* O programa do Exemplo 2 não reconhece "Amor a Roma" como uma cadeia palíndroma.
  Use a função toupper(), declarada em ctype.h, para resolver esse problema (essa
  função converte uma letra minúscula em maiúscula) */

#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"


int main(void) {
  char s[256];
  Fila F =fila(256);
  Pilha P =pilha(256);
  printf("\nFrase? ");
  gets(s);

  for(int i=0; s[i]; i++)
      s[i]=toupper(s[i]);
    if(isalpha(s[i]) ) {
      enfileira(s[i],F);
      empilha(s[i],P);
    }
  while(!vaziaf(F) && desenfileira(F) == desempilha(P));
  if( vaziaf(F) ) puts("A frase e palindroma");
  else puts("A frase naoe palindroma");
  destroif(&F);
  destroip(&P);
  return 0;
}


/* #include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"


int main(void) {
  char s[256];
  int i=0, cont=0;
  Fila F =fila(256);
  Pilha P =pilha(256);
  printf("\nFrase? ");
  gets(s);

  for(i=0; s[i]; i++)
      s[i]=toupper(s[i]);
    if(isalpha(s[i]) ) {
      enfileira(s[i],F);
      empilha(s[i],P);
    }
    do {
        if(desenfileira(F) != desempilha(P)){
            cont==cont++;
        }
    }while(!vaziaf(F));

    if( cont==0 ) 
        puts("A frase e palindroma");
    else 
        puts("A frase naoe palindroma");

    destroif(&F);
    destroip(&P);
    return 0;
}
*/