#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *izq;
    nodo *der;
};

//PROTOTIPOS
nodo *crearNodo(int);
nodo *arbol = NULL;
void insertarNodo(nodo *&, int);
void mostrarArbol(nodo *, int);
bool busquedaArbol(nodo *, int);

int main(){
    int dato, opt, contador = 0;
    char siNo;
    
    //MENU
    do{
        cout<<"\n============Menu============"  <<endl;
        cout<<"1. Insertar un Nuevo Nodo"       <<endl;
        cout<<"2. Mostrar Arbol"                <<endl;
        cout<<"3. Buscar nodo"                  <<endl;
        cout<<"4. Salir"                  <<endl<<endl;
        cout<<"Elija una opcion para continuar: ";
        cin>>opt;
        
        //OPCIONES DEL MENU
        switch(opt){
            case 1:
                cout<<"Digite un numero: ";
                cin>>dato;
                insertarNodo(arbol, dato);                
                break;
            case 2: 
                cout<<"Mostrando Arbol completo: "<<endl;
                mostrarArbol(arbol, contador);
                break;
            case 3:
                cout<<"Digite elemento a buscar: ";
                cin>>dato;
                if(busquedaArbol(arbol, dato) == true){
                    cout<<dato<<" fue encontrado en el arbol"<<endl;
                }
                else{
                    cout<<"El elemento no fue encontrado"<<endl;
                }
                break;
        }    
    }while(opt != 4);
    
    return 0;
}

//////////////////////////////////////////////////
//FUNCION PARA CREAR UN NUEVO NODO
nodo *crearNodo(int n){
    nodo *nuevo_nodo = new nodo();
    
    nuevo_nodo->dato = n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;
    
    return nuevo_nodo;
}
//////////////////////////////////////////////////
//INSERTAR NODOS
void insertarNodo(nodo *&arbol, int n){
    if(arbol == NULL){ //Si el arbol esta vacio
        nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else{//Si el arbool tiene un nodo o mas
        int valorRaiz = arbol->dato; //Se obtiene valor de raiz
        if(n < valorRaiz){//Si elemento es menor a la raiz se inserta izquierda
            insertarNodo(arbol->izq, n);
        }
        else{//Si el elemento es mayor a la raiz, se inserta en la derecha
            insertarNodo(arbol->der, n);
        }
    }
} 
//////////////////////////////////////////////////
//MOSTRAR ARBOL
void mostrarArbol(nodo *arbol, int cont){
    if(arbol == NULL){//Si el arbol esta vacio
        return;
    }
    else{
        mostrarArbol(arbol->der, cont+1);
        for(int i=0; i<cont; i++){
            cout<<"  ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq, cont+1);
    }
}
//////////////////////////////////////////////////
//BUSQUEDA DE UN NODO
bool busquedaArbol(nodo *arbol, int n){
    if(arbol == NULL){ //Si arbol esta vacio
        return false;
    } 
    else if(arbol->dato == n){
        return true;
    }
    else if(n < arbol->dato){
        return busquedaArbol(arbol->izq, n);
    }
    else{
        return busquedaArbol(arbol->der, n);
    }
}
