/*
Complete o programa a seguir, execute-o e analise os resultados.
...
int main(void) {
// precisamos usar malloc para criar vetores muito grandes!
int *v = malloc(1e8*sizeof(int));
puts(" n msort");
for(int n=1e7; n<=1e8; n+=1e7) {
preenche(v,n,1);
double t = clock();
msort(v,n);
double m = (clock()-t)/CLOCKS_PER_SEC;
printf("%9d %5.1f\n",n,m);
}
free(v);
return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int v[], int p, int m, int u) {
    int *w = malloc((u - p + 1) * sizeof(int));
    int i = p, j = m + 1, k = 0;
    while (i <= m && j <= u)
        w[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    while (i <= m)
        w[k++] = v[i++];
    while (j <= u)
        w[k++] = v[j++];
    for (k = 0; k <= u - p; k++)
        v[p + k] = w[k];
    free(w);
}

void ms(int v[], int p, int u) {
    if( p==u ) return;
    int m = (p+u)/2;
    ms(v,p,m);
    ms(v,m+1,u);
    intercala(v,p,m,u);
}

void msort(int v[], int n) {
    ms(v,0,n-1);
}

void preenche(int v[], int n, int s) {
    srand(s);
    for (int i = 0; i < n; i++) 
        v[i] = rand() % 1000;
}

int main(void) {
    int *v = malloc(100000000 * sizeof(int)); // Alocando memória para o vetor
    puts(" n msort");
    for(int n = 10000000; n <= 100000000; n += 10000000) {
        preenche(v, n, 1);
        double t = clock();
        msort(v, n);
        double m = (clock() - t) / CLOCKS_PER_SEC;
        printf("%9d %5.1f\n", n, m);
    }
    free(v); // Liberando memória alocada para o vetor
    return 0;
}
