/*
Crie a função recursiva cr(n), que exibe uma 
contagem progressiva de n>=0 até 1.

*/
#include <stdio.h>
void cr(int n) {
if( n==0 ) return;
printf("%d\n",n);
cr(n-1);
}
int main(void) {
int n;
printf("Num? ");
scanf("%d",&n);
cr(n);
return 0;
}
