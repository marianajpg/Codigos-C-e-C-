/* Crie a função recursiva bsr(v,n), que usa a função empurra() e a estratégia do bubble
sort, para organizar os n itens do vetor v em ordem crescente.
int v[9] = {51,82,38,99,75,19,69,46,27};
bsr(v,9);
exibe(v,9);
Saída: {19,27,38,46,51,69,75,82,99}

*/

#include <stdio.h>

void troca(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void empurra(int v[], int u) {
    for (int i = 0; i < u; i++) {
        if (v[i] > v[u]) {
            troca(v, i, u);
        }
    }
}

void bsr(int v[], int n) {
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        empurra(v, n - 1 - i);
    }
    bsr(v, n - 1);
}

void exibe(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

int main() {
    int v[9] = {51, 82, 38, 99, 75, 19, 69, 46, 27};
    bsr(v, 9);
    exibe(v, 9);
    return 0;
}
