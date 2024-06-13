/*
Crie a função recursiva resto(m,n), que devolve o resto da divisão inteira do número natural m
pelo número natural n0, usando apenas subtração
*/


#include <stdio.h>

int resto(int m, int n) {


    if(m<n){
        return m;
    } else {
        return resto(m-n, n);
    }

} 
int main(void) {
  int n=0,m=0;
  printf("Insira um número  ");
  scanf("%d",&m);
  printf("Insira outro número (maior que 0) ");
  scanf("%d",&n);
  printf("%d mod %d = %d", m, n, resto(m,n));
  return 0;
}
