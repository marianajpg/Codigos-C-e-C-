/* Crie a função intervalo(p,u), que cria e devolve uma lista contendo inteiros consecutivos
de p até u (para p > u). Por exemplo, a chamada intervalo(-2,3) deve devolver a lista
[-2,-1,0,1,2,3]. Se p <= u, a função deve devolver uma lista vazia. */

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
        if(L->prox == NULL)
            printf("%d ", L->item);
        else
            printf("%d, ", L->item);
        L = L->prox;
    }
    printf("]\n");
}

Lista intervalo(int p, int u) {
    Lista L = NULL;
    if (p < u) {
        for (int i = p; i <= u; i++) {
            no_novo_final(i, &L);
        }
    }
    return L;
}

int main(void) {
    int fim, inicio;

    printf("Digite o número de inicio do intervalo: ");
    scanf("%d", &inicio);

    printf("Digite o número final do intervalo: ");
    scanf("%d", &fim);

    Lista resultado = intervalo(inicio, fim);
    exibe(resultado);

    return 0;
}
