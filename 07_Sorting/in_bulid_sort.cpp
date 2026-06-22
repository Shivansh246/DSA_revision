#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    /// sort function takes iterators as input
    sort(arr,arr+n);// arr-> pointer to first index, arr+n-> pointer to last index

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}