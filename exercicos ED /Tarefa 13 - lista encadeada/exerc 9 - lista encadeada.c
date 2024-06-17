/* Crie a função maximo(L), que devolve o maior item da lista L (se L estiver vazia, erro fatal).*/



  #include <stdio.h>
  #include <stdlib.h>

  typedef int Item;
  typedef struct no {
      Item item;
      struct no *prox;
  } *Lista;

 void maximo(Lista L) {
    if (L == NULL) {
        printf("Erro fatal: a lista está vazia.\n");
        return;
    }

    Item maior = L->item;
    while (L != NULL) {
        if (L->item > maior)
            maior = L->item;
        L = L->prox;
    }
    printf("O maior numero da lista é: %d\n", maior);
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
      Lista I = NULL; 
      int tamanho, item, i;

      printf("Digite o tamanho da lista encadeada: ");
      scanf("%d", &tamanho);

      printf("Digite os %d elementos da lista:\n", tamanho);
      for (i = 0; i < tamanho; i++) {
          scanf("%d", &item);
          I = no(item, I); 
      }
        maximo(I);

      return 0;
  }
