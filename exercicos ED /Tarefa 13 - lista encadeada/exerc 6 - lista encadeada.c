/*
Crie a função intervalo(n), que devolve uma lista com os inteiros consecutivos de 1 até n*/
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

Lista intervalo(int n) {
    Lista lista = NULL;
    for (int i = n; i >= 1; i--) {
        lista = no(i, lista);
    }
    return lista;
}

int main(void) {
  int n=0;
  printf("Insira n para que os inteiros consecutivos de 1 até n sejam exibidos  ");
  scanf("%d", &n);
  
  Lista A = intervalo(n);
  exibe(A);
    eturn 0;
}
