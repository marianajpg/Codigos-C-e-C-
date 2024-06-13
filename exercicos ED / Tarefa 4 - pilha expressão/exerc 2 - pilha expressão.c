/* Altere o programa do Exemplo 4, substituindo a função posfixa() pela segunda versão. Em seguida, teste-o com as seguintes expressões infixas:
((2 * 3) + (8 / 4))
9 – 5 – 1
2 + 3 * 4 - 5
(3 + 4) * (8 - 6) / 2 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h" 

int prio(char o) {
    switch( o ) {
    case '(': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    }
    return -1; // operador inválido!
}

 char *posfixa(char *e) {
        static char s[256];
        int j = 0;
        Pilha P = pilha(256);
        for(int i=0; e[i]; i++)
        if( e[i]=='(' ) empilha('(',P);
        else if( isdigit(e[i]) ) s[j++] = e[i];
        else if( strchr("+-/*",e[i]) ) {
        while( !vaziap(P) && prio(topo(P))>=prio(e[i]) )
        s[j++] = desempilha(P);
        empilha(e[i],P);
        }
        else if( e[i] == ')' ) {
        while( topo(P)!='(' )
        s[j++] = desempilha(P);
        desempilha(P);
        } 
        while( !vaziap(P) )
        s[j++] = desempilha(P);
        s[j] = '\0';
        destroip(&P);
        return s;
    }




int main(void) {

  char e[513];
  printf("Infixa? ");
  gets(e);
  printf("Posfixa: %s\n", posfixa(e));
  return 0;

}


