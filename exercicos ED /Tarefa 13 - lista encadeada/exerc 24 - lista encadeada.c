/* Crie a função recursiva replace(x,y,L), que substitui ocorrências de x por y na lista L.


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


void replace(int x, int y, Lista L) {
    if (L == NULL) {
        
        return;
    } else if (L->item == x) {
        
        L->item = y;
    }
    replace(x, y, L->prox);
}

    int main(void) {
        Lista A = NULL;
        int tamanho, item, x, y ;

        printf("Digite o tamanho da lista encadeada: ");
        scanf("%d", &tamanho);

        printf("Digite os %d elementos da lista A:\n", tamanho);
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &item);
            no_novo_final(item, &A);
        }

        printf("Qual elemento você deseja sibstituir na lista? ");
        scanf("%d", &x);
        printf("Por qual elemento o número %i será substituido?", x);
        scanf("%d", &y);
        printf("A lista A é: ");
        exibe(A);
        printf("A lista A após a substituição é: ");
        replace(x, y, A);
        exibe(A);


        return 0;
    }

