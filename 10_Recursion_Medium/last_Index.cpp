#include <bits/stdc++.h>
using namespace std;
int last_index(int arr[],int n,int x,int i){
    if(i==-1){
        return -1;
    }
    if(arr[i]==x){
        return i;
    }
    return last_index(arr,n,x,i-1);
}
int last_index2(int arr[],int n,int x){
    if(n==0){
        return -1;
    }
    if(arr[n-1]==x){
        return n-1;
    }
    return last_index2(arr,n-1,x);
}
/// recursion from start to end to find the last Index
int last_index3(int arr[],int n,int x,int i){
    if(i==n){
        return -1;
    }
    int lastIndex=last_index3(arr,n,x,i+1);
    if(lastIndex==-1){
        if(arr[i]==x){
            return i;
        }else{
            return -1;
        }
    }else{
        return lastIndex;
    }
}
int main(){
    int arr[]={1,5,3,1,6};
    cout<<"Last Index = "<<last_index3(arr,5,1,0);
    return 0;
}