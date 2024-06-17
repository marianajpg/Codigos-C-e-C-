/* Crie a função recursiva clone(L), que devolve uma cópia da lista L. */

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

  Lista clone(Lista L) {
      if (L == NULL) {
          return NULL; 
      } else {
          Lista novo = malloc(sizeof(struct no)); 
          if (novo == NULL) {
              printf("Erro: falha na alocação de memória\n");
              exit(EXIT_FAILURE);
          }
          novo->item = L->item; 
          novo->prox = clone(L->prox);
          return novo; 
      }
  }

  int main(void) {
      Lista I = NULL;
      int tamanho, item;

      printf("Digite o tamanho da lista encadeada: ");
      scanf("%d", &tamanho);

      printf("Digite os %d elementos da lista:\n", tamanho);
      for (int i = 0; i < tamanho; i++) {
          scanf("%d", &item);
          no_novo_final(item, &I);
      }

      printf("Lista original: ");
      exibe(I);
      printf("\n");

      Lista copia = clone(I); 

      printf("Cópia da lista: ");
      exibe(copia);
      printf("\n");

      return 0;
  }
