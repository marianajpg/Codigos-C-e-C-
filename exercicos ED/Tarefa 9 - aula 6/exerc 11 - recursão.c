/*
Crie a função recursiva quoc(m,n), que devolve o quociente da divisão inteira do número natural
m pelo número natural n0, usando apenas soma e subtração.
  */


#include <stdio.h>

int quoc(int m, int n) {


    if(m<n){
        return 0;
    } else {
        return 1 + quoc(m-n, n);
    }

} 
int main(void) {
  int n=0,m=0;
  printf("Insira um número  ");
  scanf("%d",&m);
  printf("Insira outro número (maior que 0) ");
  scanf("%d",&n);
  printf("%d / %d = %d", m, n, quoc(m,n));
  return 0;
}
