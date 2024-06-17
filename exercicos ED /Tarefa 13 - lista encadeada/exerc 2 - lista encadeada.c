/*
Altere a função exibe(), de modo que os itens da lista sejam exibidos entre colchetes e
separados por vírgulas. A lista vazia deve ser exibida como [].
Por exemplo, após a alteração da função exibe(), a execução do código abaixo deve produzir
a saída indicada a seguir:
...
int main(void) {
Lista I = no(3,no(1,no(5,NULL)));
exibe(I);
return 0;
}
Saída:
[3,1,5]*/

#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    return 0;
}
