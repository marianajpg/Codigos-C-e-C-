/*
Crie a função recursiva inv(s,p,u), que inverte a string s, cujo primeiro caractere está na
posição p e cujo último caractere está na posição u. A função deve devolver s como resposta
*/
#include <stdio.h>
#include <string.h>

void inv(char s[], int p, int u) {
    if (p < u) {
        char temp = s[p];
        s[p] = s[u];
        s[u] = temp;
        inv(s, p + 1, u - 1);
    }
}

int main() {
    char s[100];
    printf("Insira uma frase: ");
    fgets(s, 100, stdin);

    // Removendo o caractere de nova linha do final da string
    if (s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }

    int tamanho = strlen(s);
    inv(s, 0, tamanho - 1);

    printf("Frase invertida: %s\n", s);
    return 0;
}
