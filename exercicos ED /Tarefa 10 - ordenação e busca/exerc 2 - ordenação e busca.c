/* Crie a função recursiva empurra(v,u), que “empurra” um item máximo do vetor v para a
posição u de v, possivelmente alterando a ordem dos demais itens do vetor. Por exemplo, o
código abaixo deve produzir a saída indicada a seguir:
int v[9] = {51,82,38,99,75,19,69,46,27};
empurra(v,8);
exibe(v,9);
Saída: {51,38,82,75,19,69,46,27,99} */


#include <stdio.h>

void troca(int v[], int i, int j) {
  int x = v[i];
  v[i] = v[j];
  v[j] = x;
}

void bsort(int v[], int n) {
  for(int i=1; i<n; i++)
    for(int j=0; j<n-i; j++)
      if( v[j]>v[j+1] )
        troca(v,j,j+1);
}

void exibe(int v[], int n){
  for(int i=0; i<n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
}

void empurra(int v[], int u) {
    for (int i = 0; i < u; i++) {
        if (v[i] > v[u]) {
            troca(v, i, u);
        }
    }
}

int main(void) {
    int v[9] = {51,82,38,99,75,19,69,46,27};
    empurra(v, 8);
    exibe(v, 9);
    return 0;
}
