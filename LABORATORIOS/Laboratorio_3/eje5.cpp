//Nombre: Daniel Alfredo Quesada Cortez
//Carnet: 00147619
//Ejercicio 5
#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class listaSimple{
private:
    node *list;
public:
    listaSimple(){
        list = NULL;
    }
    void llenarLista(int);
    void mostrarLista();
    void mostrarListaRec();
    void mostrarListaRec(node *);
};

int main(){
    listaSimple lista;
    int n;
    char siNo;
    do{
        cout<<"Ingresar un dato: ";
        cin>>n;
        lista.llenarLista(n);
        cout<<"Desea ingresar otro dato(s/n)?";
        cin>>siNo;
    }while(siNo == 's');
    cout<<"\nMostrando Lista Funcion Normal: "<<endl;
    lista.mostrarLista();
    cout<<"\nMostrando Lista Funcion Recursiva Inversa: "<<endl;
    lista.mostrarListaRec();
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////
//LLENAR LISTA
void listaSimple::llenarLista(int n){
    node *New_node = new node;
    New_node->data = n;
    New_node->next = list;
    list = New_node;
}
////////////////////////////////////////////////////////////////////////////////////
//MOSTRAR LISTA
void listaSimple::mostrarLista(){
    node *actual = new node;
    actual = list;
    
    while(actual != NULL){
        cout<<actual->data<<" ";
        actual = actual->next;
    }
}
////////////////////////////////////////////////////////////////////////////////////
//MOSTRAR LISTA RECURSIVA
void listaSimple::mostrarListaRec(){
    mostrarListaRec(list);
}
void listaSimple::mostrarListaRec(node *p){
    if(p != NULL){
        mostrarListaRec(p->next);
        cout<< p->data <<endl;
    }
}
