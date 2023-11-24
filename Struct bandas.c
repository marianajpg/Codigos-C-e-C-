/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
//Guilherme Theo e Mariana


    struct Banda
{
    char nome[20];
    int integrantes, rank;
    char genero[10];
    
}
;
struct Banda banda[5];

int main() 
{
    int ranking;

    for (int i=0; i<5; i++)
    {
        printf("Digite o nome da %dª banda:", i+1);
        getchar();
        fflush(stdin);
        fgets(banda[i].nome,20,stdin);
        
        printf("Digite o genero da %dª banda:", i+1);
        getchar();
        fflush(stdin);
        fgets(banda[i].genero,10,stdin);
        
        printf("Digite a quantidade de integrantes da %dª banda:", i+1);
        scanf("%d", &banda[i].integrantes);
        
        printf("Digite o ranking da %dª banda:", i+1);
        scanf("%d", &banda[i].rank);
        
        printf("-----------------------------------------------------\n");
        
    }
    
    
    printf("\nBANDAS DIGITADAS");
    for (int i=0; i<5; i++)
    {
        printf("\nRanking da banda: %d",banda[i].rank);
        printf("\nNome da banda %d: %s", i+1, banda[i].nome);
        printf("\nGenero da banda %d: %s", i+1, banda[i].genero);
        printf("\nNumero de integrantes da banda %d: %d", i+1, banda[i].integrantes);
    }
    
    
    printf("\n\nDigite o ranking da banda desejada (1 à 5)");
    scanf("%i", &ranking);
    
    for (int i=0; i<5; i++)
    {
        if (banda[i].rank==ranking)
        {
            printf("Ranking escolhido: %d", ranking);
            printf("Nome da banda %d: %s", i+1, banda[i].nome);
            printf("Genero da banda %d: %s", i+1, banda[i].genero);
            printf("Numero de integrantes da banda %d: %d", i+1, banda[i].integrantes);
        }
        
    }
    
  return 0;
}