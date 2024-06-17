/*
Complete e execute o programa a seguir.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
...
int main(void) {
srand(time(NULL));
Lista A = aleatoria(10,100);
exibe(A);
return 0;
}
*/
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

Lista aleatoria(int tamanho, int max_valor) {
    Lista lista = NULL;
    for (int i = 0; i < tamanho; i++) {
        int valor = rand() % (max_valor + 1);
        lista = no(valor, lista);
    }
    return lista;
}

int main(void) {
  int tamanho=0, max=0;
  srand(time(NULL));
  printf("Insira quantos numeros aleatórios devem ser exibidos ");
  scanf("%d", &tamanho);
  printf("Insira o maior numero que pode ser exibido ");
  scanf("%d", &max);
  Lista A = aleatoria(tamanho, max);
  exibe(A);
  return 0;
}
