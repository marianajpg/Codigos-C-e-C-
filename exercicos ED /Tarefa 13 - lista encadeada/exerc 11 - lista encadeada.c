/* Crie a função inversa(L), que cria e devolve uma cópia invertida da lista L. Por exemplo, se
L for a lista [1,2,3], a chamada inversa(L) deve devolver a lista [3,2,1].*/


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

  Lista inversa(Lista L) {
      if (L == NULL) {
          return NULL;
      }
      if (L->prox == NULL) {
          return L;
      }
      Lista restante = inversa(L->prox);
      L->prox->prox = L;
      L->prox = NULL;
      return restante;
  }


  void exibe(Lista L) {
      while (L != NULL) {
          printf("%d ", L->item);
          L = L->prox;
      }
      printf("\n");
  }

  int main(void) {
      Lista I = NULL;
      int tamanho, item, i;

      printf("Digite o tamanho da lista encadeada: ");
      scanf("%d", &tamanho);

      printf("Digite os %d elementos da lista:\n", tamanho);
      for (i = 0; i < tamanho; i++) {
          scanf("%d", &item);
          no_novo_final(item, &I);
      }

      printf("Lista original: ");
      exibe(I);

      // Inverter a lista
      Lista inversa_I = inversa(I);

      printf("Lista invertida: ");
      exibe(inversa_I);

      return 0;
  }
