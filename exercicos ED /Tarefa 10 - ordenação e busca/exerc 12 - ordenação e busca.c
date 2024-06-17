/*
  Crie a função recursiva rbsearch(x,v,p,u), que faz uma busca binária para determinar
se o item x está no vetor crescente v, indexado de p até u.
  */

#include <stdio.h>

int rbsearch(int x, int v[], int p, int u) {
    // Caso base: se p for maior que u, significa que o intervalo de busca é inválido
    if (p > u)
        return 0;

    // Encontramos o índice médio entre p e u
    int m = (p + u) / 2;

    // Se o elemento do índice médio for igual a x, retornamos 1 (verdadeiro)
    if (v[m] == x)
        return 1;
    // Se x for menor que o elemento do índice médio, fazemos uma busca na metade esquerda
    else if (x < v[m])
        return rbsearch(x, v, p, m - 1);
    // Se x for maior que o elemento do índice médio, fazemos uma busca na metade direita
    else
        return rbsearch(x, v, m + 1, u);
}

int main(void) {
    int v[8] = {19, 27, 31, 48, 52, 66, 75, 80};
    printf("27: %d\n", rbsearch(27, v, 0, 7));
    printf("51: %d\n", rbsearch(51, v, 0, 7));
    return 0;
}
