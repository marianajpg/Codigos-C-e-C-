/* Crie a função recursiva prod(m,n), que devolve o produto de dois números naturais m e n,
usando apenas soma e subtração. */

#include <stdio.h>

int prod(int m, int n) {

    if(n>1){
       n--;
       return m+prod(m, n);
    } else {
        return m;
    }

} 
int main(void) {
  int n=0,m=0;
  printf("Insira um número  ");
  scanf("%d",&n);
  printf("Insira outro número que será multiplicado pelo primeiro  ");
  scanf("%d",&m);
  printf("%d * %d = %d", n, m, prod(m,n));
  return 0;
}

