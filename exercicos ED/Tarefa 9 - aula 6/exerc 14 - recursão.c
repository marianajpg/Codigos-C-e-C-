/*
  Crie a função recursiva sd(n), que devolve a soma dos dígitos do número natural n. Por exemmplo, 
  a chamada sd(7859) deve devolver 29 (pois 7+8+5+9 = 29)
*/


#include <stdio.h>

int sd(int n) {
    int cont=0;

    if(n<0||n==0){
        return 0;
    } else{
        return (n % 10) + sd(n / 10); 

    } 
}
int main(void) {
  int n=0;
  printf("Insira um número ");
  scanf("%d",&n);

  printf("A soma dos digitos de %d é: %d", n, sd(n));
  return 0;
}
