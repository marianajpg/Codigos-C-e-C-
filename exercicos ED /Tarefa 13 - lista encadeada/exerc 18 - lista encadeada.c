/* Crie a função recursiva in(x,L), que verifica se o item x está na lista L.*/



    #include <stdio.h>
    #include <stdlib.h>

    typedef int Item;
    typedef struct no {
        Item item;
        struct no *prox;
    } *Lista;

int in_recursivo(int x, Lista L) {
    if (L == NULL) {
        return 0; 
    }
    if (L->item == x) {
        return 1; 
    }
    return in_recursivo(x, L->prox);
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

    printf("Digite o número que deseja saber se está na lista ou não:\n");
    scanf("%d", &x);

    if (in_recursivo(x, I)) {
        printf("%d pertence à lista criada.\n", x);
    } else {
        printf("%d não pertence à lista criada.\n", x);
    }

    return 0;
}


