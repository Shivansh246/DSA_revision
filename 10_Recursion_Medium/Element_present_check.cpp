#include <bits/stdc++.h>
using namespace std;

bool check(int arr[],int n,int x){
    if(n==0){
        return false;
    }
    if(arr[0]==x){
        return true;
    }
    return check(arr+1,n-1,x);
}
bool check2(int arr[],int n,int x){
    if(n==0){
        return false;
    }
    bool remArr = check2(arr+1,n-1,x);
    if(remArr){
        return true;
    }
    if(arr[0]==x){
        return true;
    }
    return false;
}
bool check3(int arr[],int n,int x){
    if(n==0){
        return false;
    }
    bool remArr = check3(arr,n-1,x);
    if(remArr){
        return true;
    }
    if(arr[n-1]==x){
        return true;
    }
    return false;
}
/// index approach

bool check4(int arr[],int n,int x,int i){
    if(i==n){
        return false;
    }
    if(arr[i]==x){
        return true;
    }
    return check4(arr,n,x,i+1);
}

int main(){
    int arr[]={1,2,3,4,5};

    if(check4(arr,5,3,0)){
        cout<<"Present";
    }else{
        cout<<"Not present";
    }
    return 0;
}