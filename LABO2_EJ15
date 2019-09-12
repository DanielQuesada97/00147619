//Nombre: Daniel Alfredo Quesada Cortez    Carnet:00147619


//EJ15
#include <iostream>
using namespace std;

void merge(int A[], int low, int high, int mid){
    int i, j, k, c[50];
    i=low;
    k=low;
    j=mid+1;
    while(i<=mid&&j<=high){
        if(A[i]<A[j]){
            c[k]=A[i];
            k++;
            i++;
        }
        else{
            c[k] = A[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        c[k] = A[i];
        k++;
        i++;
    }
    while(j<=high){
        c[k] = A[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++){
        A[i]=c[i];
    }
}

void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid;
        mid=(low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);

        merge(a,low,high,mid);
    }
    return;
}

int main(){
    int a[]={5,1,2,4,3};
    int k=3, low=0, high=4;

    mergeSort(a,low,high);
    
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
