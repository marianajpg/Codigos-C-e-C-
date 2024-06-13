//Faça a alteração mínima necessária para que o programa do exercício anterior ordene os números em ordem decrescente, eliminando números repetidos.
  
#include <stdio.h>
#include "pilha.h"

int main()
{
    int quantidade=0, cont=0, item=0;

    printf("Quantos números pretende inserir? ");
    scanf("%i", &quantidade);

    Pilha pilhaA = pilha(quantidade);
    Pilha pilhaB = pilha(quantidade);

    while (quantidade>cont || cont==1){
      printf("Insira o %iº número ", cont+1);
      scanf("%i", &item);
      empilha(item, pilhaA);
      cont++;
    }

    while (!vaziap(pilhaA)) {
      item = desempilha(pilhaA);

      while (!vaziap(pilhaB) && topo(pilhaB) < item) {
        empilha(desempilha(pilhaB), pilhaA);
      }
      empilha(item, pilhaB);
    }
    
    while(!vaziap(pilhaB)){
        empilha(desempilha(pilhaB),pilhaA);
        if(!vaziap(pilhaA) && !vaziap(pilhaB) && topo(pilhaB)==topo(pilhaA)){
           desempilha(pilhaB);
        }
    }

  printf("Números ordenados: ");
  while (!vaziap(pilhaA)) {
      printf("%d ", desempilha(pilhaA));
  }


    destroip(&pilhaA);
    destroip(&pilhaB);

    return 0;
}