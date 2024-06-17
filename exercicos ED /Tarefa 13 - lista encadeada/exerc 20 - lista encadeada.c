/* Crie a função recursiva minimum(L), que devolve o menor item da lista L




  #include <stdio.h>
  #include <stdlib.h>

  typedef int Item;
  typedef struct no {
      Item item;
      struct no *prox;
  } *Lista;

 void minimum(Lista L) {
    if (L == NULL) {
        printf("Erro fatal: a lista está vazia.\n");
        return;
    }

    Item menor = L->item;
    while (L != NULL) {
        if (L->item < menor)
            menor = L->item;
        L = L->prox;
    }
    printf("O menor numero da lista é: %d\n", menor);
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
    minimum(I);

      return 0;
  }
