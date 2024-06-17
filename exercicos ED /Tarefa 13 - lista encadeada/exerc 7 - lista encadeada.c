/*
Complete e execute o programa a seguir.
#include <stdio.h>
#include <stdlib.h>
...
int main(void) {
Lista H = no(4,no(2,NULL));
Lista I = no(3,no(1,no(5,NULL)));
printf("H = "); exibe(H);
printf("I = "); exibe(I);
printf("Pressione enter");
getchar();
anexa(&H,I);
printf("H = "); exibe(H);
printf("I = "); exibe(I);
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

void anexa(Lista *H, Lista I) {
    if (*H == NULL) {
        *H = I;
    } else {
        Lista temp = *H;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = I;
    }
}

int main(void) {
    Lista H = no(4, no(2, NULL));
    Lista I = no(3, no(1, no(5, NULL)));

    printf("H = ");
    exibe(H);
    printf("I = ");
    exibe(I);

    printf("Pressione enter\n");
    getchar();

    anexa(&H, I);

    printf("H = ");
    exibe(H);
    printf("I = ");
    exibe(I);

    return 0;
}
