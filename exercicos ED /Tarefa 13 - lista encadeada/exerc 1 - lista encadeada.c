/* Complete e execute o programa a seguir.
#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct no {
Item item;
struct no *prox;
} *Lista;
...
int main(void) {
Lista I = no(3,no(1,no(5,NULL)));
exibe(I);
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
    while (L != NULL) {
        printf("%d\n", L->item);
        L = L->prox;
    }
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
    return 0;
}
