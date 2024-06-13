/* Crie a função recursiva par(n), que determina se o natural n é par, usando apenas subtração.*/

#include <stdio.h>

void ParOuNao(int n) {

  if(n==0 ){
    printf("É par");
   }else {
     if (n<0)
      printf("Não é par");
     else
      ParOuNao(n-2);
    }
} 
int main(void) {
  int n;
  printf("Insira um numero para identificar se é par ou não ");
  scanf("%d",&n);
  ParOuNao(n);
  return 0;
}