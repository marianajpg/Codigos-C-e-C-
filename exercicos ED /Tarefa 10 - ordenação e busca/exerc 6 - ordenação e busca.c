/*Faça um programa para testar o funcionamento da função a seguir, que preenche um vetor v
com n inteiros aleatórios, gerados a partir da semente s, escolhidos no intervalo [0,999].
void preenche(int v[], int n, int s) {
srand(s); // definida em stdlib.h
for(int i=0; i<n; i++) v[i] = rand()%1000;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche(int v[], int n, int s) {
    srand(s); // definida em stdlib.h
    for (int i = 0; i < n; i++) 
        v[i] = rand() % 1000;
}

void exibe(int v[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

int main() {
    int n = 10;
    int v[n];
    int s = time(NULL); // Usando o tempo atual como semente

    preenche(v, n, s);
    exibe(v, n);

    return 0;
}
