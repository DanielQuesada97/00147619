#include <iostream>
#include <stdlib.h>

using namespace std;
//NODO
struct node{
    int data;
    node *next;
};

//CLASE
class listaSimple{
private:
    node *head, *tail;
    node *list;
    int *array = new int;

public:
    listaSimple(){
        head = NULL;
        tail = NULL;
        list = NULL;
    }
    //FUNCIONES
    void agregarLista(int);   //Agrega y orderna los elementos de la lista de forma ascendente
    void mostrarLista();        //Muestra todos los elementos de la lista
    void shellSort();
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
        cout<<"3. Ordenar Lista via SHELL SORT" <<endl;
        cout<<"4. Salir"                  <<endl<<endl;
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
            case 3: // ORDENAR LISTA VIS SHELLSORT
                lista.shellSort();
                break;
        }    
    }while(opt != 4);
    
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//AGREGAR A LISTA DE MANERA ORDENADA ASCENDENTE
void listaSimple::agregarLista(int n){
    node *New_node = new node;
    New_node->data = n; 
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

    cout<<n<<" fue agregado a la lista!"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//MOSTRAR LISTA
void listaSimple::mostrarLista(){
    node *actual = new node;
    actual = list;
    
    while(actual != NULL){
        cout<<actual->data<<" ";
        actual = actual->next;
    }        
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//SHELL SORT
void listaSimple::shellSort(){
    int i = 0;
    node *actual = new node;
    actual = list;
        
    while(actual != NULL){
        array[i] = actual->data;
        cout << array[i]<<" ";
        actual = actual->next;  
        ++i;
    }
    
    int N = sizeof(array) / sizeof(array[0]);
    
    for (int gap = N / 2; gap > 0; gap /= 2){
        for (int k = gap; k < N; k += 1){
            int temp = array[k];
            int j;
            for (j = k; j >= gap && array[j - gap] > temp; j -= gap)
                    array[j] = array[j - gap];
            array[j] = temp;
        }
    }
    
    cout << "\nArray after shell sort: \n";

	for (int l = 0; l < N; l++)
		cout << array[l] << " ";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
