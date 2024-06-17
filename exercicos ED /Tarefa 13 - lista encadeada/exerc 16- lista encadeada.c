/* Crie a função recursiva rnd(n,m), que devolve uma lista com n itens aleatórios em [0, m-1].*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;

typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

void exibe(Lista L) {
    printf("[");
    if (L != NULL) {
        printf("%d", L->item);
        L = L->prox;
        while (L != NULL) {
            printf(",%d", L->item);
            L = L->prox;
        }
    }
    printf("]\n");
}

Lista no(Item item, Lista prox) {
    Lista novo = (Lista)malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro: falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->item = item;
    novo->prox = prox;
    return novo;
}

Lista rnd(int n, int m, Lista lista) {
    if (n <= 0) {
        return lista;
    }
    int valor = rand() % m;
    lista = no(valor, lista);
    return rnd(n - 1, m, lista);
}


int main(void) {
    int n, max;
    srand(time(NULL));

    printf("Insira quantos números aleatórios devem ser gerados: ");
    scanf("%d", &n);

    printf("Insira o maior número que pode ser gerado: ");
    scanf("%d", &max);

    Lista A = rnd(n, max, NULL);
    exibe(A);

    return 0;
}