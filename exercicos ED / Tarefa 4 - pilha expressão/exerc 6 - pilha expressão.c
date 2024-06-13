/* Crie a função valpre(e), que devolve o valor da expressão aritmética prefixa e. Em seguida, faça um programa para testar a função */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int valpre(char *e) {
    int len = strlen(e);
    _strrev(e); // Inverte a expressão prefixa
    Pilha P = pilha(len);

    for (int i = 0; i < len; i++) {
        if (isdigit(e[i])) {
            empilha(e[i] - '0', P); // Converte o caractere numérico para inteiro e empilha
        } else if (strchr("+-*/", e[i])) {
            if (vaziap(P)) {
                printf("Erro: Pilha vazia durante a avaliação da expressão prefixa.\n");
                destroip(&P);
                return -1;
            }

            int x = desempilha(P);

            if (vaziap(P)) {
                printf("Erro: Pilha vazia durante a avaliação da expressão prefixa.\n");
                destroip(&P);
                return -1;
            }

            int y = desempilha(P);

            switch (e[i]) {
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
                    if (y == 0) {
                        printf("Erro: Divisão por zero.\n");
                        destroip(&P);
                        return -1;
                    }
                    empilha(x / y, P);
                    break;
            }
        }
    }

    if (vaziap(P)) {
        printf("Erro: Pilha vazia após avaliação da expressão prefixa.\n");
        destroip(&P);
        return -1;
    }

    int resultado = desempilha(P);
    destroip(&P);
    return resultado;
}

int main() {
    char expressao_prefixa[100];

    printf("Digite a expressao aritmetica prefixa: ");
    fgets(expressao_prefixa, sizeof(expressao_prefixa), stdin);

    expressao_prefixa[strcspn(expressao_prefixa, "\n")] = '\0';

    int resultado = valpre(expressao_prefixa);

    if (resultado != -1) {
        printf("O resultado da expressao prefixa '%s' é: %d\n", expressao_prefixa, resultado);
    }

    return 0;
}

