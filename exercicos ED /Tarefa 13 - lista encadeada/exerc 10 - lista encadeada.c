/* Crie a função pertence(x,L), que verifica se o item x pertence à lista L.*/




    #include <stdio.h>
    #include <stdlib.h>

    typedef int Item;
    typedef struct no {
        Item item;
        struct no *prox;
    } *Lista;

   void pertence(int x, Lista L) {
      if (L == NULL) {
          printf("Erro fatal: a lista está vazia.\n");
          return;
      }

      while (L != NULL) {
          if (L->item == x){
            printf("%i pertence a lista criada", x);
            return;
          }
          L = L->prox;
      }
     printf("%i não pertence a lista criada", x);

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
        int tamanho, item, x, i;

        printf("Digite o tamanho da lista encadeada: ");
        scanf("%d", &tamanho);

        printf("Digite os %d elementos da lista:\n", tamanho);
        for (i = 0; i < tamanho; i++) {
            scanf("%d", &item);
            I = no(item, I); 
        }
        printf("Digite oo número que deseja saber se está na lista ou não:\n");
        scanf("%d", &x);
        pertence(x, I);

        return 0;
    }

