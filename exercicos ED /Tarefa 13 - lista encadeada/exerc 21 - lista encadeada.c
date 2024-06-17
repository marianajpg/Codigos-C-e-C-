/* Crie a função recursiva sorted(L), que verifica se a lista L está ordenada.*/


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

int sorted(Lista L) {
    if (L == NULL || L->prox == NULL) {
        return 1; 
    }
    if (L->item > L->prox->item) {
        return 0; 
    } else {
        return sorted(L->prox); 
    }
}


  int main(void) {
      Lista I = NULL;
      int tamanho, item ;

      printf("Digite o tamanho da lista encadeada: ");
      scanf("%d", &tamanho);

      printf("Digite os %d elementos da lista:\n", tamanho);
      for (int i = 0; i < tamanho; i++) {
          scanf("%d", &item);
          no_novo_final(item, &I);
      }


     if(sorted(I)){
         printf("A lista está ordenada");
     } else{
         printf("A lista não está ordenada");
     }


      return 0;
  }

