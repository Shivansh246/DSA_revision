#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int key){
    int s=0,e=n-1;
    while(s<=e){
        int mid= s + (e-s)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            e=mid-1;
        }else{
            s = mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<"Enter the key: ";
    int key;
    cin>>key;
    int pos = binarySearch(arr,n,key);
    if(pos==-1){
        cout<<"Key not present";
    }else{
        cout<<"Key found at index "<<pos;
    }
    return 0;
}