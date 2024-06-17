/*
  Adicione no programa do exercício anterior uma função para calcular a soma dos itens da lista.
  Por exemplo, considerando que I aponta a lista de inteiros [3,1,5], a chamada soma(I)
  deve devolver a resposta 9.*/


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

int tamanho(Lista L) {
    int count = 0;
    while (L != NULL) {
        count++;
        L = L->prox;
    }
    return count;
}

int soma(Lista L) {
    int sum = 0;
    while (L != NULL) {
        sum =sum+ L->item;
        L = L->prox;
    }
    return sum;
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
  int n1=0, n2=0, n3=0;
  printf("Insira o primeiro numero de 3  ");
  scanf("%d", &n1);
  printf("Insira o segundo numero de 3  ");
  scanf("%d", &n2);
  printf("Insira o terceiro numero de 3  ");
  scanf("%d", &n3);

  
  Lista I = no(n1, no(n2, no(n3, NULL)));
  exibe(I);
  printf("Tamanho = %d\n", tamanho(I));
  printf("Soma = %d\n", soma(I));
  return 0;
}
