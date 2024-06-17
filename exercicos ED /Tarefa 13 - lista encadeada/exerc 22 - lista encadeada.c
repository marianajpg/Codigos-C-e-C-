/* Crie a função recursiva equal(A,B), que verifica se as listas A e B são iguais.


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

int equal(Lista A, Lista B) {
    if (A == NULL && B == NULL) {
        return 1;
    } else if (A == NULL || B == NULL) {
        return 0; 
    } else if (A->item!= B->item) {
        return 0;
    } else {
        return equal(A->prox, B->prox); 
    }
}


  int main(void) {
      Lista A = NULL, B=NULL;
      int tamanho, item ;

      printf("Digite o tamanho da lista encadeada: ");
      scanf("%d", &tamanho);

      printf("Digite os %d elementos da lista A:\n", tamanho);
      for (int i = 0; i < tamanho; i++) {
          scanf("%d", &item);
          no_novo_final(item, &A);
      }

    printf("Digite os %d elementos da lista B:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &item);
        no_novo_final(item, &B);
    }


     if(equal(A,B)){
         printf("A lista A é igual a lista B");
     } else{
         printf("A lista A não é igual a lista B");
     }


      return 0;
  }

