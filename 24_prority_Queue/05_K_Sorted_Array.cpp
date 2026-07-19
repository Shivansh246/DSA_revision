#include <iostream>
#include<queue>
using namespace std;

void kSortedArray(int *arr,int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int s=0;
    for(int i=k;i<n;i++){
        arr[s]=pq.top();
        s++;
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        arr[s]=pq.top();
        pq.pop();
        s++;
    }
}
int main(){
    /*k-Sorted Array:
    an array in which after sorting each element in descending order, has moved either (k-1) positions to the right 
    or k-1 positions to the left or reamined at the same place*/
    int arr[]={10,12,6,7,9};
    int k=3;

    kSortedArray(arr,5,k);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}