//NOMBRE: DANIEL ALFREDO QUESADA CORTEZ
//CARNET: 00147619
//EXAMEN CORTO 02

#include <iostream>

using namespace std;

struct node{
    char letra;
    node *next;
};

class murcielago{
private:
    node *list;
public:
    murcielago(){
        list = NULL;
    }
    void addWord();
    void leerCaracteres(string);
    void codificar(char);
    void decodificar();
    void mostrarLista();
    void eliminarLista();
};

int main(){
    murcielago lista;
    char palabra[50];
    
    //Digitando palabra
    cout<<"Ingrese palabra a codificar: "<<endl;
    cin.getline(palabra, 50, '\n');
    
    //Leyendo y codificando palabra
    lista.leerCaracteres(palabra);
    
    //Mostrando palabra ya codificada dentro de lista
    cout<<"\nLa lista codificada es:"<<endl;
    lista.mostrarLista();
    
    //Decodificando palabra y mostrando nuevamente
    cout<<"\nLa frase original es: "<<endl;
    lista.decodificar();
    
    //Eliminando Lista
    cout<<"\nEliminando lista..."<<endl;
    lista.eliminarLista();
    
    //Mostrando lista nuevamente
    lista.mostrarLista();
    
    return 0;
}
//////////////////////////////////////////////////////////////////////
//LITERAL D
void murcielago::leerCaracteres(string palabra){
    cout<<"Leyendo Caracteres antes de ingresar a la lista..."<<endl;
    for(int i = 0; palabra[i] != '\0'; i++){
        cout<<palabra[i];
        codificar(palabra[i]); //Lamando funcion del literal 'e'
    }
    cout<<"\n\nLos caracteres fueron ingresados a la lista..."<<endl;
}

//////////////////////////////////////////////////////////////////////
//LLENANDO LISTA
void murcielago::codificar(char letra){
    switch(letra){
        case 'm': letra = '0'; break;
        case 'M': letra = '0'; break;
        case 'u': letra = '1'; break;
        case 'U': letra = '1'; break;
        case 'r': letra = '2'; break;
        case 'R': letra = '2'; break;
        case 'c': letra = '3'; break;
        case 'C': letra = '3'; break;
        case 'i': letra = '4'; break;
        case 'I': letra = '4'; break;
        case 'e': letra = '5'; break;
        case 'E': letra = '5'; break;
        case 'l': letra = '6'; break;
        case 'L': letra = '6'; break;
        case 'a': letra = '7'; break;
        case 'A': letra = '7'; break;
        case 'g': letra = '8'; break;
        case 'G': letra = '8'; break;
        case 'o': letra = '9'; break;
        case 'O': letra = '9'; break;
        default: letra = letra; break;
    }
    
    node *New_node = new node;
    New_node->letra = letra; 
    node *aux1;
    node *aux2;
    
    New_node->next = NULL;
    if(list == NULL) {
        list = New_node;
    }
    else {
        aux1 = list;
        aux2 = NULL;
        while (aux1 != NULL){
            aux2 = aux1;
            aux1 = aux1->next;
        }
        aux2->next = New_node;
    }
}

//////////////////////////////////////////////////////////////////////
//MOSTRAR LISTA
void murcielago::mostrarLista(){
    node *actual = new node;
    actual = list;
    
    while(actual != NULL){       
        cout<<actual->letra;   
        actual = actual->next;
    }
    if(list == NULL){
        cout<<"La lista esta vacia!"<<endl;
    }
}
//////////////////////////////////////////////////////////////////////
//DECODIFICANDO LISTA
void murcielago::decodificar(){
    node *actual = new node;
    actual = list;
    
    while(actual != NULL && actual->letra != '\0'){
        switch(actual->letra){
            case '0': cout<<'m'; break;
            case '1': cout<<'u'; break;
            case '2': cout<<'r'; break;
            case '3': cout<<'c'; break;
            case '4': cout<<'i'; break;
            case '5': cout<<'e'; break;
            case '6': cout<<'l'; break;
            case '7': cout<<'a'; break;
            case '8': cout<<'g'; break;
            case '9': cout<<'o'; break;
            default: cout<<actual->letra;
        }   
        actual = actual->next;
    }        
}
//////////////////////////////////////////////////////////////////////
//ELIMINANDO LISTA
void murcielago::eliminarLista(){
    node *aux_delete = list;
    node *aux2;
    while(aux_delete != NULL){
        aux2 = aux_delete->next;
        delete aux_delete;
        aux_delete = aux2;
    }
    cout<<"Lista Eliminada!"<<endl;
    list = NULL;
}
//////////////////////////////////////////////////////////////////////
