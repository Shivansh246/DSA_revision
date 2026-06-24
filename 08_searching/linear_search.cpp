#include<bits/stdc++.h>
using namespace std;
int linear_search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;/// returning an invalid inex; 
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key to search: ";
    int key;
    cin>>key;

    int pos = linear_search(arr,n,key);
    if(pos==-1){
        cout<<"Key not found";
    }else{
        cout<<"Key found at index "<<pos;
    }
    return 0;
}