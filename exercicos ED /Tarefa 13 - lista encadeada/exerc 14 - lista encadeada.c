/* Crie a função recursiva sum(L), que devolve a soma dos itens da lista L.*/




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

  int soma(Lista L) {
      if (L == NULL)
          return 0;
      else
          return L->item + soma(L->prox);
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

      printf("A soma de todos os itens da lista é: %i ", soma(I));

      return 0;
  }

