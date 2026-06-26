#include <bits/stdc++.h>
using namespace std;
int index(int arr[], int n,int x,int i){
    if(i==n){
        return -1;
    }
    if(arr[i]==x){
        return i;
    }
    return index(arr,n,x,i+1);
}

int main(){
    int arr[]={5,2,3,5,5};
    cout<<index(arr,5,5,0);
    cout<<endl;
    
    return 0;
}