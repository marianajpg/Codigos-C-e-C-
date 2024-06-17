/*
Crie a função recursiva rlsearch(x,v,n), que faz uma busca linear para determinar se o
item x está no vetor v, que tem n itens.
*/

#include <stdio.h>

int rlsearch(int x, int v[], int n) {
    // Caso base: se o tamanho do vetor for 0, o elemento não está presente
    if (n == 0)
        return 0;

    // Se o primeiro elemento do vetor for igual a x, retornamos 1 (verdadeiro)
    if (v[0] == x)
        return 1;

    // Chamada recursiva com o vetor reduzido em 1 e o tamanho diminuído em 1
    return rlsearch(x, v + 1, n - 1);
}

int main(void) {
    int v[8] = {19, 27, 31, 48, 52, 66, 75, 80};
    printf("27: %d\n", rlsearch(27, v, 8));
    printf("51: %d\n", rlsearch(51, v, 8));
    return 0;
}
