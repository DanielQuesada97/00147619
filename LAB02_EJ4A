//Nombre: Daniel Alfredo Quesada Cortez    Carnet:00147619

//EJERCICIO 4A

#include <iostream>
#include <cmath>
using namespace std;

double funcionPi(int n, double k);

int main(){
    int k;
    cout<<"Ingrese el valor de k: ";
    cin>>k;
    cout<<4*funcionPi(k,0);
    
    return 0;
}

double funcionPi(int k, double n){    
    if(k==0){
        return n;
    }
    else{
        return n+((pow(-1,k+1))/((2*k)-1))+funcionPi(k-1,n);
    }
}
