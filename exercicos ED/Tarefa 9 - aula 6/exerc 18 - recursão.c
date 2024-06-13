/*
Crie a função recursiva pal(s,p,u), que informa se a string s, cujo primeiro caractere está na
posição p e cujo último caractere está na posição u, é palíndroma (ignorando brancos)
*/
#include <stdio.h>
#include <string.h>

int pal(char s[], int p, int u) {
    if (p >= u) {
        return 1; 
    } else {
        while (p < u && s[p] == ' ') {
            p++;
        }
        while (p < u && s[u] == ' ') {
            u--;
        }

        if (s[p] != s[u]) {
            return 0; 
        } else {
            return pal(s, p + 1, u - 1);
        }
    }
}

int main() {
    char s[100];
    printf("Insira uma frase: ");
    fgets(s, sizeof(s), stdin);

    if (s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }

    int tamanho = strlen(s);
    int resultado = pal(s, 0, tamanho - 1);

    if (resultado) {
        printf("A frase \"%s\" é um palíndromo.\n", s);
    } else {
        printf("A frase \"%s\" não é um palíndromo.\n", s);
    }

    return 0;
}