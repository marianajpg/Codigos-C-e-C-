/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

void classificar(float L1, float L2, float L3, float h);
int main()
{
    float s=0, x=0, y=0, z=0;
    cout<<"Classificar triângulo\n";
    cout<<"Digite a medida do maior lado\n";
    cin>>x;
    cout<<"Digite a medida do outro lado\n";
    cin>>y;
    cout<<"Digite a medida do lado restante\n";
    cin>>z;
    s=y+z;
    classificar (x, y, z, s);
}
    
    
void classificar(float L1, float L2, float L3, float h)
{
    if (h<=L1)
    {
        cout<<"Nao e um triangulo\n";
        
    } else {
        cout<<"É um triangulo\n";
        
        if (L1==L2)
        {
            if (L2==L3) 
            {
                cout<<"O triangulo e equilatero";
            } else {
                cout<<"O triangulo e isosceles";
            }
        } else {
            if (L1==L3 || L2==L3)
            {
                cout<<"O triangulo e isosceles";
                
            } else {
                cout<<"O triangulo e escaleno";
            }
        }
        
    }
}
