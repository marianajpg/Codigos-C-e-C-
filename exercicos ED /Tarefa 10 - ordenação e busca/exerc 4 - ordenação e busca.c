/* Complete o programa a seguir, execute-o e analise os resultados.
#include <stdio.h>
...
int main(void) {
int v[8] = {31,48,60,80,19,27,52,75};
intercala(v,0,3,7);
exibe(v,8);
int w[9] = {10,82,27,38,41,53,60,75,99};
intercala(w,0,1,8);
exibe(w,9);
return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

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

void exibe_concatenado(int v[], int w[], int nv, int nw) {
    printf("{");
    for (int i = 0; i < nv; i++) {
        printf("%d", v[i]);
        if (i < nv - 1) {
            printf(",");
        }
    }
    for (int i = 0; i < nw; i++) {
        printf("%d", w[i]);
        if (i < nw - 1) {
            printf(",");
        }
    }
    printf("}\n");
}

int main(void) {
    int v[8] = {31, 48, 60, 80, 19, 27, 52, 75};
    int w[9] = {10, 82, 27, 38, 41, 53, 60, 75, 99};
    intercala(v, 0, 3, 7);
    intercala(w, 0, 1, 8);
    exibe_concatenado(v, w, 8, 9);
    return 0;
}


////////////////////////////////////////////////////////////
/*
#include <stdio.h>

void intercala(int v[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = v[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = v[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
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

int main(void) {
    int v[8] = {31, 48, 60, 80, 19, 27, 52, 75};
    intercala(v, 0, 3, 7);
    exibe(v, 8);

    int w[9] = {10, 82, 27, 38, 41, 53, 60, 75, 99};
    intercala(w, 0, 1, 8);
    exibe(w, 9);

    return 0;
}
*/