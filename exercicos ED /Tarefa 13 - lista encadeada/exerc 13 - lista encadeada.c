/* Crie a função recursiva len(L), que devolve o tamanho da lista L.*/
#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

void no_novo_final(Item item, Lista *L) {
    Lista novo = malloc(sizeof(struct no));
    if (novo == NULL) {
        printf("Erro: falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novo->item = item;
    novo->prox = NULL;

    if (*L == NULL) {
        *L = novo;
    } else {
        Lista aux = *L;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void exibe(Lista L) {
    printf("[");
    while (L != NULL) {
        if (L->prox == NULL)
            printf("%d", L->item);
        else
            printf("%d, ", L->item);
        L = L->prox;
    }
    printf("]");
}

int len(Lista L) {
    if (L == NULL)
        return 0;
    else
        return 1 + len(L->prox);
}

int main(void) {
    Lista I = NULL;
    int item;

    printf("Digite os elementos da lista encadeada (digite -587 para parar):\n");

    while (1) {
        scanf("%d", &item);
        if (item == -587)
            break;
        no_novo_final(item, &I);
    }

    printf("A lista ");
    exibe(I);
    printf(" possui %i elementos.\n", len(I));

    return 0;
}

