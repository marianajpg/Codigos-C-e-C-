/*
O quadrado de um natural n é a soma dos n primeiros ímpares, i.e., n²= 1 + 3 + 5 + ... + (2n-1).
Crie a função recursiva q(n), que devolve o quadrado de n, como base nesta informação.
*/

#include <stdio.h>

int quad(int n) {


    if(n<0||n==0){
        return 0;
    } else{
        return (2*n-1)+quad(n-1);
    }

} 
int main(void) {
  int n=0;
  printf("Insira um número ");
  scanf("%d",&n);

  printf("O quadrado de %d é: %d", n, quad(n));
  return 0;
}
