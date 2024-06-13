/*
Crie a função recursiva h(n), que devolve o número mínimo de movimentos para resolver o
problema das Torres de Hanói com n discos. Por exemplo, h(3) deve devolver 7.
*/

#include <stdio.h>

int h(int n) {
    if (n == 1) {
        return 1; 
    } else {
        return 2 * h(n - 1) + 1; 
    }
}

int main() {
    int n = 0;
    printf("Digite a quantidade de discos: ");
    scanf("%d", &n);
    printf("O número mínimo de movimentos para resolver o problema das Torres de Hanói com %d discos é: %d\n", n, h(n)); 
    return 0;
}