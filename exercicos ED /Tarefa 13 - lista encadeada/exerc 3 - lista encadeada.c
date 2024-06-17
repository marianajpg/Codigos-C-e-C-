/*
Complete e execute o programa a seguir.
#include <stdio.h>
#include <stdlib.h>
...
int main(void) {
Lista I = no(3,no(1,no(5,NULL)));
exibe(I);
printf("Tamanho = %d\n",tamanho(I));
return 0;
}
*/
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

int tamanho(Lista L) {
    int count = 0;
    while (L != NULL) {
        count++;
        L = L->prox;
    }
    return count;
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
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    printf("Tamanho = %d\n", tamanho(I));
    return 0;
}
