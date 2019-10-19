#include <iostream>
#include <stdlib.h> //new

using namespace std;
//NODO
struct node{
    int data;
    node *next;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCIONES
void addStack(node *&, int);
void removeStack(node *&,int &);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    node *stack=NULL;
    int n;
    
    char opt;
    do{
        cout<<"Do you wish to add an integer to the stack(y/n)?"<<endl;
        cin>>opt;
        if(opt=='y'){
            cout<<"Type an integer: ";
            cin>>n;
            addStack(stack,n);
        }
    }while(opt=='y');
    
    cout<<"\nRemoving elements from stack..."<<endl;
    while(stack != NULL){         //while it hasn't reached the end of the stack
        removeStack(stack,n);
//        if(stack != NULL){
//            cout<<n<<" ";
//        }
//        else
//            cout<<n<<".";
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void addStack(node *&stack, int n){
    node *New_node = new node();      //A dynamic memory space is created for the node
    New_node->data = n;               //n value is stored inside the node(data)
    New_node->next = stack;           //First node points to NULL(declared at main)
    stack = New_node;                 //A new node is assigned to the stack.   
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void removeStack(node *&stack, int &n){
    node *aux = stack;                //auxiliary variable receives the direction of current node
    n = aux->data;                    //n receives the data stored in the current node
    stack = aux->next;                //Stack points to new node since the current node will be deleted
    cout << n <<" ";                  //Prints on screen
    delete aux;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
