#include <iostream>
using namespace std;
void selectionSort(int arr[],int n){
    /*
    for(int i=0;i<=n-2;i++){
        int smallest=INT_MAX;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<smallest){
                smallest = arr[j];
            }
        }
        if(arr[i]>smallest){
            swap(arr[i],smallest);
        }
    }
    Incorrrect code as it swaps "smallest" which is just a variable not a array element
    */
   for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
   }
//    for(int i=0;i<n-1;i++){
//         int min_index=i+1;
//         for(int j = i+2;j<n;j++){
//             if(arr[j]<arr[min_index]){
//                 min_index=j;
//             }
//         }
//         if(arr[i]>arr[min_index]){
//             swap(arr[i],arr[min_index]);
//         }
//    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}