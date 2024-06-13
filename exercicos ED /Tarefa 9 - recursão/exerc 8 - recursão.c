/*
Crie a função recursiva hanoi(n,origem,auxiliar,destino), queresolve o problema dasTorres de
Hanói, movendo n discos da torre origem, para a torre destino, usando a torre auxiliar. Por
exemplo, a chamada hanoi(3, 'A', 'B', 'C') deve resolver o problema discutido no Exemplo 6.

Mova n-1 de A para B  Mova 1 de A para C   Mova n-1 de B para C
*/
#include <stdio.h>

void hanoi(int n, char orig, char dest, char aux) {
    if (n == 1) {
        printf("Mover %d de %c para %c\n", n, orig, dest);
    } else {
        hanoi(n - 1, orig, aux, dest);
        printf("Mover %d de %c para %c\n", n, orig, dest);
        hanoi(n - 1, aux, dest, orig);
    }
}

int main() {
    int n = 0;
    printf("Digite a quantidade de discos: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B'); 
    return 0;
}
