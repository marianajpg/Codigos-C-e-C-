//Usando pilha, crie uma função para verificar se uma expressão composta apenas por chaves,colchetes e parênteses, representada por uma cadeia de caracteres, está ou não balanceada. Porexemplo, as expressões "[{()()}{}]" e "{[([{}])]}" estão balanceadas, mas asexpressões "{[(}])" e "{[)()(]}" não estão.

  #include <stdio.h>
  #include "pilha.h"

  void balanceadaounao(Pilha Expressao){
      int abreparenteses=0, abrecolchetes=0, abrechaves=0, fechaparenteses=0, fechachaves=0, fechacolchetes=0, topo_pilha=0;
      while(!vaziap(Expressao)){

          topo_pilha=desempilha(Expressao);

          switch(topo_pilha){
            case '(':
              abreparenteses++;
            break;
            case '[':
              abrecolchetes++;
            break;
            case '{':
              abrechaves++;
            break;
            case ')':
              if (abreparenteses==0||abreparenteses!=(fechaparenteses++)){
                abreparenteses--;
              } else{
                fechaparenteses++;
              }
            break;
            case ']':
              if (abrecolchetes==0||abrecolchetes!=(fechacolchetes++)){
                  abrecolchetes--;
              } else{
                fechacolchetes++;
              }
            break;
            case '}':
              if (abrechaves==0||abrechaves!=(fechachaves++)){
                   abrechaves--;
              } else{
                fechachaves++;
              }
            break;
          }

      }

      if(abreparenteses!=fechaparenteses||abrecolchetes!=fechacolchetes||abrechaves!=fechachaves){
        printf("A expressão não está balanceada!");
      } else{
        printf("A expressão está balanceada!");
      }

  }

  int main4()
  {
      int cont=0;
      char expressao[100];

      Pilha pilhaExpressao = pilha(100);

      printf("Escreva uma expressão composta apenas por chaves, colchetes e parênteses\n");
      fflush(stdin);
      fgets(expressao,100,stdin);

      for(cont=0; expressao[cont]!='\0';cont++){
          empilha(expressao[cont],pilhaExpressao);
      }

      balanceadaounao(pilhaExpressao);

      destroip(&pilhaExpressao);

      return 0;
  }
