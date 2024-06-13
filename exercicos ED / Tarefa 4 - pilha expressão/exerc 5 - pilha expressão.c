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
  int j = 0;
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
  }
  _strrev(expressaoPrefixa);
  expressaoPrefixa[j] = '\0';
  destroip(&PilhaA);
  return expressaoPrefixa;
}

int main(void) {

  char expressaoInfixa[513];
  printf("Infixa? ");
  gets(expressaoInfixa);
  printf("Prefixa:");

  return 0;
}

/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *prefixa(char *expressaoInfixa) {
  int j = 0;
  static char expressaoPrefixa[256];
  Pilha PilhaA = pilha(256);
  int tamanho = strlen(expressaoInfixa);

  for (int i = tamanho - 1; i >= 0; i--) {
    if (isdigit(expressaoInfixa[i])) {
      expressaoPrefixa[j++] = expressaoInfixa[i];
    } else if (strchr("+*-/", expressaoInfixa[i])) {
      empilha(expressaoInfixa[i], PilhaA);
    } else if (expressaoInfixa[i] == '(') {
      expressaoPrefixa[j++] = desempilha(PilhaA);
    } else if (expressaoInfixa[i] == ')') {
      continue; // Ignora o fechamento de parênteses
    }
  }

  while (!vaziap(PilhaA)) {
    expressaoPrefixa[j++] = desempilha(PilhaA);
  }

  expressaoPrefixa[j] = '\0';
  destroip(&PilhaA);

  // Inverte a expressão prefixa
  int n = strlen(expressaoPrefixa);
  for (int i = 0; i < n / 2; i++) {
    char temp = expressaoPrefixa[i];
    expressaoPrefixa[i] = expressaoPrefixa[n - i - 1];
    expressaoPrefixa[n - i - 1] = temp;
  }

  return expressaoPrefixa;
}

int main(void) {
  char expressaoInfixa[513];
  printf("Infixa? ");
  gets(expressaoInfixa);
  printf("Prefixa: %s\n", prefixa(expressaoInfixa));
  return 0;
}


*/