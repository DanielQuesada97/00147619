//Nombre: Daniel Alfredo Quesada Cortez    Carnet:00147619

//Lab2_EJ7
#include <iostream>
using namespace std;

void numNaturales(int a, int b);

int main(){
    int a, b;
    
    cout<<"Ingrese el valor de a: ";
    cin>>a;
    cout<<"ingrese el valor de b: ";
    cin>>b;
    
    cout<<"La lista de numeros naturales entre "<<a<<" y "<< b <<" es: "<<endl;
    numNaturales(a,b);
    
    return 0;
}

void numNaturales(int a, int b){
    if(a<(b-1)){
        cout<<++a<<" ";
        numNaturales(a,b);
    }
    if(b<(a-1)){
        cout<<++b<<" ";
        numNaturales(a,b);
    }
}
