#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    node *next;
};

void addQueue(node *&, node*&, int);
void removefromQueue(node *&, node*&, int &);
bool emptyQueue(node *);   //function to determine whether the Queue is empty or not

int main(){
    node *head = NULL;
    node *tail = NULL;
    
    int n;
    char opt;
    
    do{
        cout<<"Type an integer: "<<endl;
        cin>>n;
        addQueue(head,tail,n);
        cout<<"Do wish to add another integer to Queue(y/n)? "<<endl;
        cin>>opt;
    }while(opt == 'y');
    
    cout<<"The elements in the Queue are: "<<endl;
    while(head != NULL){
        removefromQueue(head,tail,n);
        cout<<n<<" ";
    }
    
    return 0;
}

void addQueue(node *&head, node *&tail, int n){
    node *New_node = new node();
    New_node->data = n;
    New_node->next = NULL;
    
    if(emptyQueue(head)){
        head = New_node;
    }
    else{
        tail->next = New_node;
    }
    tail = New_node;
}

void removefromQueue(node *&head, node *&tail, int &n){
    n = head -> data;
    node *aux = head;
    
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
    }
    delete aux;
}

bool emptyQueue(node *head){
    return (head==NULL)? true : false;
}
