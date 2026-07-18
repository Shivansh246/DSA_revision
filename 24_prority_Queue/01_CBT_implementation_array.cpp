#include <iostream>
using namespace std;


///Implemented by me
// 12 6 5 100 1 9 0 14
void insert(int arr[],int &size,int x){
    if(size==0){
        arr[0]=x;
        size++;
        return;
    }
    int childIndex=size;
    arr[childIndex]=x;
    size++;
    int parentIndex = (childIndex-1)/2;
    while(parentIndex>=0 && arr[parentIndex]>arr[childIndex]){
        swap(arr[parentIndex],arr[childIndex]);
        childIndex=parentIndex;
        parentIndex=(childIndex-1)/2;
    }
}
void removeMin(int arr[],int &size){
    swap(arr[size-1],arr[0]);
    size--;
    int parentIndex=0;
    int leftchild = 2*parentIndex+1;
    int rightchild = 2*parentIndex+2;
    while((rightchild<size || leftchild <size) && (arr[parentIndex]>arr[leftchild] || arr[parentIndex]>arr[rightchild])){
        if(leftchild>=size){
            return;
        }
        if(rightchild>=size){
            return;
        }
        if(arr[leftchild]<arr[rightchild]){
            swap(arr[leftchild],arr[parentIndex]);
            parentIndex=leftchild;
            leftchild=2*parentIndex+1;
            rightchild=2*parentIndex+2;
        }else{
            swap(arr[parentIndex],arr[rightchild]);
            parentIndex=rightchild;
            rightchild=2*parentIndex+2;
            leftchild=2*parentIndex+1;
        }

    }
}
int main(){
    int arr[100];
    int size =0;
    insert(arr,size,12);
    insert(arr,size,6);
    insert(arr,size,5);
    insert(arr,size,100);
    insert(arr,size,1);
    insert(arr,size,9);
    insert(arr,size,0);
    insert(arr,size,14);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    removeMin(arr,size);
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    removeMin(arr,size);
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}