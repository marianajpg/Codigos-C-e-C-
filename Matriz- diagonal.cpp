/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int A[2][2], B[2][2], i=0, j=0, fat=1, aux=1;
    for (i=0; i<=1; i=i+1)
    {
        for (j=0; j<=1; j=j+1)
        {
            A[i][j]=0;
            B[i][j]=0;
        }
    }
    cout<<"Matriz B = fatoriais da Matriz A\n";
    for (i=0; i<=1; i=i+1)
    {
        for (j=0; j<=1; j=j+1)
        {
            do 
            {
              cout<<"Insira os valores inteiros positivos da matriz A\n";
              cin>>A[i][j];
            } while (A[i][j]<0);
        }
    }
    
    
    for (i=0; i<=1; i=i+1)
    {
        for (j=0; j<=1; j=j+1)
        {
            while (aux<=A[i][j])
            {
                fat=fat*aux;
                aux=aux+1;
            }
            B[i][j]=fat;
        }
    }

    
    cout<<"Matriz A:";
    for (i=0; i<=1; i=i+1)
    {
        cout<<"\n";
        for (j=0; j<=1; j=j+1)
        {
            
            cout<<A[i][j]<<" ";
        }
    }
    cout<<"\n\nMatriz B:";
    for (i=0; i<=1; i=i+1)
    {
        cout<<"\n";
        for (j=0; j<=1; j=j+1)
        {
            
            cout<<B[i][j]<<" ";
        }
    }
    
    return 0;
}
