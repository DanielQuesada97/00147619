//Elabore una función que le devuelva el mayor de los números ingresados a un arreglo.

#include <iostream>
using namespace std;

int mayorNumero(int *n);

int main(){
    int n[5];
    cout<<"Escriba 5 numeros para llenar el arreglo: "<<endl;
    for(int i=0;i<5;i++){
        cin>>n[i];
    }
    cout<<"El mayor de los numeros ingresados es: "<<mayorNumero(n)<<endl;
    return 0;
}

int mayorNumero(int *n){
    int mayor=0;
    for(int i=0;i<5;i++){
        if(mayor<n[i]){
            mayor=n[i];
        }
    }
    return mayor;
}
