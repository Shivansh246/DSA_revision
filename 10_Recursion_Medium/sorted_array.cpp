#include <bits/stdc++.h>
using namespace std;

bool isa(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    bool isSmallArraySorted = isa(arr+1,n-1);
    return isSmallArraySorted;
}
bool sortedFromReverse(int arr[],int n){
    if(n==0|| n==1){
        return true;
    }
    if(arr[n-1]<arr[n-2]){
        return false;
    }
    bool isSmallArraySorted=sortedFromReverse(arr,n-1);
    return isSmallArraySorted;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(sortedFromReverse(arr,n)){
        cout<<"Sorted";
    }else{
        cout<<"Not sorted";
    }
    return 0;
}
