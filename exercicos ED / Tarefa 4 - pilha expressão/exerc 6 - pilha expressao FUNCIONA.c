/* Crie a função valpre(e), que devolve o valor da expressão aritmética prefixa e. Em seguida, faça um programa para testar a função */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *obter_prefixa(char *expressaoInfixa) {
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




int valpre(char *e, int len, int *erro) {
    Pilha P = pilha(len);

    for (int i = len - 1; i >= 0; i--) { // Percorre a expressão prefixa da direita para a esquerda
        if (isdigit(e[i])) {
            empilha(e[i] - '0', P); // Converte o caractere numérico para inteiro e empilha
        } else if (strchr("+-*/", e[i]!= NULL)) {
            if (vaziap(P)) {
                printf("Erro: Pilha vazia durante a avaliação da expressão prefixa.\n");
                destroip(&P);
                *erro = 1;
                return -1;
            }

            int y = desempilha(P); // O segundo operando é desempilhado primeiro

            if (vaziap(P)) {
                printf("Erro: Pilha vazia durante a avaliação da expressão prefixa.\n");
                destroip(&P);
                *erro = 1;
                return -1;
            }

            int x = desempilha(P); // O primeiro operando é desempilhado depois

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
                        *erro = 1;
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
        *erro = 1;
        return -1;
    }

    int resultado = desempilha(P);
    destroip(&P);
    *erro = 0;
    return resultado;
}

int main() {
    char expressao[100];
    printf("Digite a expressao infixa: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0'; // Remove o caractere de nova linha

    char *expressaoPrefixa = obter_prefixa(expressao);
    printf("Prefixa: %s\n", expressaoPrefixa);

    int erro;
    int resultado = valpre(expressaoPrefixa, strlen(expressaoPrefixa), &erro);
    if (erro) {
        printf("Erro: Divisao por zero ou operador inválido.\n");
    } else {
        printf("Resultado: %d\n", resultado);
    }

    return 0;
}
