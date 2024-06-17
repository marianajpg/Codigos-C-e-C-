/* Crie a função recursiva count(x,L), que informa quantas vezes o item x ocorre na lista L.
*/


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

int count(int x, Lista L) {
    if (L == NULL) {
        return 0;
    } else if (L->item == x) {
        return 1 + count(x, L->prox); 
    } else {
        return count(x, L->prox); 
    }
}


    int main(void) {
        Lista A = NULL;
        int tamanho, item ;

        printf("Digite o tamanho da lista encadeada: ");
        scanf("%d", &tamanho);

        printf("Digite os %d elementos da lista A:\n", tamanho);
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &item);
            no_novo_final(item, &A);
        }

        printf("Qual elemento você deseja contar a ocorrência na lista? ");
        scanf("%d", &item);
        printf("O número %d aparece %d vezes na lista. \n", item, count(item, A));



        return 0;
    }

