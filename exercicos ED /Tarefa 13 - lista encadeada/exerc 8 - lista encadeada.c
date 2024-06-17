/* Crie a função ultimo(L), que devolve o último item da lista L (se L estiver vazia, erro fatal).*/


 

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

void exibe_ultimo(Lista L) {
    if (L != NULL) {
        while (L != NULL) {
          if(L->prox == NULL)
            printf("O último item da lista é: %d", L->item);
          L = L->prox;
        }
    }
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
  exibe_ultimo(I);

  return 0;
}
