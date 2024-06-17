/* Crie a função recursiva last(L), que devolve o último item da lista L.*/



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

int last(Lista L) {
    if (L == NULL) {
        printf("Erro: lista vazia\n");
        exit(EXIT_FAILURE);
    }
    if (L->prox == NULL) {
        return L->item;
    } else {
        return last(L->prox);
    }
}

int main(void) {
    Lista I = NULL;
    int tamanho, item, ;

    printf("Digite o tamanho da lista encadeada: ");
    scanf("%d", &tamanho);

    printf("Digite os %d elementos da lista:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &item);
        no_novo_final(item, &I);
    }


    printf("O ultimo elemento da lista é: %i", last(I));


    return 0;
}

