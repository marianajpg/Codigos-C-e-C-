/*Crie um programa completo para ler uma expressão aritmética na forma infixa e
exibir sua forma posfixa correspondente, bem como seu valor numérico. Por
exemplo, para a expressão infixa "2*3+8/4", o programa deve apresentar como
saída a forma posfixa "23*84/+" e o valor numérico 8. */

#include "pilha.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int prio(char o) {
  switch (o) {
  case '(':
    return 0;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  }
  return -1; // operador inválido!
}

char *posfixa(char *e) {
  static char s[256];
  int j = 0;
  Pilha P = pilha(256);
  for (int i = 0; e[i]; i++)
    if (e[i] == '(')
      empilha('(', P);
    else if (isdigit(e[i]))
      s[j++] = e[i];
    else if (strchr("+-/*", e[i])) {
      while (!vaziap(P) && prio(topo(P)) >= prio(e[i]))
        s[j++] = desempilha(P);
      empilha(e[i], P);
    } else if (e[i] == ')') {
      while (topo(P) != '(')
        s[j++] = desempilha(P);
      desempilha(P);
    }
  while (!vaziap(P))
    s[j++] = desempilha(P);
  s[j] = '\0';
  destroip(&P);
  return s;
}

int valor(char *e) {
  Pilha P = pilha(256);
  char *s = posfixa(e);

  for (int i = 0; s[i]; i++) {
    if (isdigit(s[i]))
      empilha(s[i] - '0', P);
    else {
      int y = desempilha(P);
      int x = desempilha(P);
      switch (s[i]) {
      case '+':
        empilha(x + y, P);
        break;
      case '-':
        empilha(x - y, P);
        break;
      case '*':
        empilha(x * y, P);
        break;
      case '/':
        empilha(x / y, P);
        break;
      }
    }
  }
  int z = desempilha(P);
  destroip(&P);
  return z;
}

int main(void) {
  char infixa[513];

  printf("Infixa? ");
  gets(infixa);

  printf("Posfixa: %s\n", posfixa(infixa));
  printf("Resultado: %d\n", valor(infixa));
  return 0;
}


