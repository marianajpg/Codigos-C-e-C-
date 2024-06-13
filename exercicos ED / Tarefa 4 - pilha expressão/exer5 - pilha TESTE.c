/*Crie a função prefixa(e), que devolve a forma prefixa da expressão aritmética completamente parentesiada e. Em seguida, faça um programa para testar a função.
Dicas:
Percorra a expressão infixa da direita para a esquerda.
Use strlen() para determinar o tamanho da expressão infixa.
Use _strrev() para inverter uma cadeia de caracteres.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *prefixa(char *expressaoInfixa) {
  int j = 0, cont=0 ;
  static char expresPrefixa[256];
  static char expressaoPrefixa[256];
  Pilha PilhaA = pilha(256);
  for(int i = strlen(expressaoInfixa); i>=0; i--){
    if( isdigit(expressaoInfixa[i]) ) {
      expressaoPrefixa[j++] = expressaoInfixa[i];
    } else if( strchr("+*-/",expressaoInfixa[i]) ) {
      empilha(expressaoInfixa[i], PilhaA);
    } else if( expressaoInfixa[i]=='(' ) {
      expressaoPrefixa[j++] = desempilha(PilhaA);
    }
    cont++;
  }
  expressaoPrefixa[j] = '\0';
  destroip(&PilhaA);
  
  for(int i = cont; i>=0; i--){
    expresPrefixa[j++]=expressaoPrefixa[j];
  }
  return expresPrefixa;
}

int main(void) {
  int x=0;
  char *expressaoPrefixa[256];
  char expressaoInfixa[513];
  printf("Infixa? ");
  gets(expressaoInfixa);
  printf("Prefixa: %s", prefixa(expressaoInfixa));
  return 0;
}

/*
for (int i=strlen(expressaoPrefixa); i<=0; i--) ){
  exprPrefixa[x]=expressaoPrefixa[i];
  x++;
}
*/

/*
while(vaziap(PilhaA)){
  desempilha(PilhaA);
}

for(int i=0;expressaoPrefixa[i];i++){
  empilha(expressaoPrefixa[i],PilhaA)
}
printf("Números ordenados: ");
while (!vaziap(pilhaA)) {
    printf("%d ", desempilha(pilhaA));
}
*/