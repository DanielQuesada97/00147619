//9)Funcion Recursiva

#include <iostream>
#include <math.h>
using namespace std;

int suma(int x, int n);

int main(){
    int x, n;
    cout<<"Ingrese el valor de x: ";cin>>x;
    cout<<"Ingrese el valor de n: ";cin>>n;
    cout<<suma(x,n);

    return 0;
}

int suma(int x, int n){
    if(n>0){
        return pow(x,n)+suma(pow(x,n-1)+pow(x,n-2),n-2);
    }
}
