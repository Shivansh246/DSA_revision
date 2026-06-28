#include <bits/stdc++.h>
using namespace std;/*
-> pivot : the last element whose position is to be corrected

-> partition: array before pivot -> all smaller than pivot, array after pivot-> all larger than pivot
*/
int partition(int a[],int s,int e){// my way
    int k=e;
    for(int i=s;i<e;i++){
        if(i<k){
            if(a[i]>a[k]){
                swap(a[i],a[k]);
                k=i;
            }
        }
        if(i>k){
            if(a[i]<a[k]){
                swap(a[i],a[k]);
                k=i;
            }
        }
    }
    return k;

}
int partition2(int a[],int s,int e){
    int pivot = a[e];
    int i=s;
    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[e]);
    return i;
}
void quickSort(int a[],int s,int e){
    if(s>e){
        return;
    }
    //int p = partition(a,s,e);
    int p = partition2(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}
int main(){
    int arr[]={1,5,2,0,3};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}