//NOMBRE: DANIEL ALFREDO QUESADA CORTEZ
//CARNET: 00147619
//SECCION: 01

//TAREA APORTE PARA EXAMEN CORTO 2
#include <iostream>
#include <stdlib.h>

using namespace std;
//NODO
struct node{
    int dato;
    node *next;
};

//CLASE
class listaSimple{
private:
    node *head, *tail;
    node *list;
public:
    listaSimple(){
        head = NULL;
        tail = NULL;
        list = NULL;
    }
    //FUNCIONES
    void agregarLista(int n);   //Agrega y orderna los elementos de la lista de forma ascendente
    void mostrarLista();        //Muestra todos los elementos de la lista
    void buscarLista(int);      //Busca elementos en la lista
    void eleminarNodo(int);     //Elimina un nodo
    void insertDes(int , int ); //Insertar dato despues de cierto elemento en la lista
    void eliminarLista();
    void eliminarListaRec(node *);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN
int main(){
    listaSimple lista;
    int n, n2, opt;
    char siNo;
    
    //MENU
    do{
        cout<<"\n============Menu============"  <<endl;
        cout<<"1. Agregar elemento a lista"     <<endl;
        cout<<"2. Mostrar todos los elementos"  <<endl;
        cout<<"3. Buscar en lista"              <<endl;
        cout<<"4. Eliminar de lista"            <<endl;
        cout<<"5. Insertar en lista"            <<endl;
        cout<<"6. Eliminar lista Complete"      <<endl;
        cout<<"7. Salir"                  <<endl<<endl;
        cout<<"Elija una opcion para continuar: ";
        cin>>opt;
        
        //OPCIONES DEL MENU
        switch(opt){
            case 1: //AGREGAR ELEMENTOS A LA LISTA
                do{
                    cout<<"Agregue un elemento a la lista: ";
                    cin>>n;
                    lista.agregarLista(n);
                    
                    cout<<"Desea agregar otro elemento(s/n)?"<<endl;
                    cin>>siNo;
                }while(siNo == 's');
                break;
            case 2: //MOSTRAR LISTA
                cout<< "\nElementos de la lista: "<<endl;
                lista.mostrarLista();
                break;
            case 3: //BUSCAR ELEMENTO EN LISTA
                cout<<"Elemento que desea buscar?"<<endl;
                cin>>n;
                lista.buscarLista(n);
                break;
            case 4: //ELIMINAR DE LISTA
                cout<<"Elemento a eliminar: ";
                cin>>n;
                lista.eleminarNodo(n);
                break;
            case 5: //INSERTAR ELEMENTO DESPUES DE CIERTO ELEMENTO EN LISTA.
                cout<<"Agregar un elemento a la lista: ";
                cin>>n;
                cout<<"Despues de que elemento desea insertar el dato? ";
                cin>>n2;
                lista.insertDes(n, n2);
                break;
            case 6: //ELIMINAR LISTA COMPLETA
                lista.eliminarLista();
                cout<<"La lista se ha eliminado! "<<endl;
                break;
        }    
    }while(opt != 7);
    
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//AGREGAR A LISTA DE MANERA ORDENADA ASCENDENTE
void listaSimple::agregarLista(int n){
    node *New_node = new node;
    New_node->dato = n;
    node *aux1 = list;
    node *aux2;

    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(list == aux1){
        list = New_node;
    }
    else{
        aux2->next = New_node;
    }
    New_node->next = aux1;

    cout<<n<<" fue agregado a la lista!"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//MOSTRAR LISTA
void listaSimple::mostrarLista(){
    node *actual = new node;
    actual = list;
    
    while(actual != NULL){
        cout<<actual->dato<<" ";
        actual = actual->next;
    }        
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//BUSCAR ELEMENTO EN LISTA
void listaSimple::buscarLista(int n){
    bool flag=false;

    node *actual = new node();
    actual = list;

    while((actual != NULL) && (actual->dato <= n)){
        if(actual->dato == n){
            flag = true;
        }
        actual = actual->next;
    }
    if(flag == true){
        cout<<"El elemento "<<n<<" se ha encontrado en la lista!"<<endl;
    }
    else{
        cout<<"El elemento "<<n<<" NO esta en la lista!"<<endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//ELIMINAR NODO DE LISTA
void listaSimple::eleminarNodo(int n){
    if(list != NULL){
        node *aux_delete;
        node *previous = NULL;
        aux_delete = list;

        while((aux_delete != NULL) && (aux_delete->dato != n)){
            previous = aux_delete;
            aux_delete = aux_delete->next;
        }

        if(aux_delete == NULL){
            cout<<"Ese elemento no existe!"<<endl;
        }
        else if(previous == NULL){
            list = list->next;
            delete aux_delete;
        }
        else{
            previous->next = aux_delete->next;
            delete aux_delete;
        }
    }
    else{
        cout<<"La lista esta vacia!"<<endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//INSERTAR ELEMENTOS DESPUES DE UN ELEMENTO DETERMINADO
void listaSimple::insertDes(int n, int n2) {
    node* aux1 = new node;
    aux1 -> dato = n;
    aux1 -> next = NULL;

    node* aux2 = list;
    while(aux2->dato < n2){
        aux2 = aux2->next;
    }
    
    aux1->next = aux2->next;
    aux2->next = aux1;
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//ELIMINAR LISTA COMPLETA
void listaSimple::eliminarLista(){
    node *aux_delete = list;
    node *aux2;
    while(aux_delete != NULL){
        aux2 = aux_delete->next;
        delete aux_delete;
        aux_delete = aux2;
    }
    list = NULL;
}
