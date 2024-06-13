//Usando uma pilha, crie um programa para inverter a ordem das letras nas palavras de uma frase, sem inverter a ordem das palavras na frase. Por exemplo, se for digitada a frase "apenas um teste", o programa deverá produzir a seguinte saída: sanepa mu etset.

#include <stdio.h>
#include "pilha.h"

int main()
{
  int contespaco=0, cont=0, item=0;
  char frase[200];

  Pilha pilhaFrase = pilha(200);

  printf("Escreva uma frase que será invertida ");
  fflush(stdin);
  fgets(frase,200,stdin);


  while (frase[cont]!='\0'){
    cont++;
  }

  while(cont>=0){
    if(frase[cont]!='\0'&& frase[cont]!=' '){
      
      while (frase[cont]!=' '&& frase[cont]!='\0'){
        contespaco= cont;
        cont--;
      }

      while(frase[contespaco]!='\0'&& frase[contespaco]!=' '){
  empilha(frase[contespaco],pilhaFrase);
        contespaco++;
      }
    } else{
      empilha(frase[cont],pilhaFrase);
      cont--;
    }
  }
  


  printf("Frase invertida: ");
  while (!vaziap(pilhaFrase)) {
      printf("%c", desempilha(pilhaFrase));
  }


    destroip(&pilhaFrase);

    return 0;
}