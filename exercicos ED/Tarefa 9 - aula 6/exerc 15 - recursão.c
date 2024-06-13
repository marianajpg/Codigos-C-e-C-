/*
Crie a função recursiva qd(n), que devolve a quantidade de dígitos binários para representar o
natural n. Por exemplo, a chamada qd(13) deve devolver 4 (pois 13 em binário é 1101).
  */

#include <stdio.h>


 int ad(int n){
     if(n==0){
        return 0;
     } else{
        return 1+ad(n/2);
     }
 }

 int binaro(int n){
     int bi[30];
     int i=0;
     printf("\nO número %d representado em binário = ", n);
     while(n>0){
      bi[i]=n%2;
      n=n/2;
      i++;
    }
    for(i=i-1; i>=0; i--){
        printf("%d", bi[i]);
    }
 }

 int main(){
     int n=0;

     printf("Digite um número: ");
     scanf("%d", &n);
     printf("A quantidade de dígitos binários para representar o número %d é: %d ", n, ad(n));
     binaro(n);
     return 0;
 }