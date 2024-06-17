/* Crie a função recursiva nth(n,L), que devolve o enésimo (n>=1) item da lista L.*/




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

int nth(int n, Lista L) {
    if (n < 1 || L == NULL) {
        printf("Erro: Índice inválido\n");
        exit(EXIT_FAILURE);
    }
    if (n == 1) {
        return L->item;
    } else {
        return nth(n - 1, L->prox);
    }
}


  int main(void) {
      Lista I = NULL;
      int tamanho, item, n;

      printf("Digite o tamanho da lista encadeada: ");
      scanf("%d", &tamanho);

      printf("Digite os %d elementos da lista:\n", tamanho);
      for (int i = 0; i < tamanho; i++) {
          scanf("%d", &item);
          no_novo_final(item, &I);
      }

      printf("Gostaria de descobrir o elemento de qual posição? ");
      scanf("%d", &n);

      printf("O enesimo elemento da lista é: %i", nth(n, I));


      return 0;
  }


