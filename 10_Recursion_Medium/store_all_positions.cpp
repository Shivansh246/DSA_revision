#include <bits/stdc++.h>
using namespace std;
void saveAllPos(int arr[],int n,int x,int i,vector<int>&v){
    if(i==n){
        return;
    }
    if(arr[i]==x){
        v.push_back(i);
    }
    return saveAllPos(arr,n,x,i+1,v);
}

int saveAllPosUsingArray(int arr[],int n,int x,int i,int out[],int j){
    if(i==n){
        return 0;
    }
    
    if(arr[i]==x){
        out[j]=i;
        return 1+saveAllPosUsingArray(arr,n,x,i+1,out,j+1);
    }
    return saveAllPosUsingArray(arr,n,x,i+1,out,j);
   
}
int main(){
    int arr[]={1,2,1,2,1};
    vector<int> v;
    saveAllPos(arr,5,1,0,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int out[10];
    int countOcccurence=saveAllPosUsingArray(arr,5,1,0,out,0);
    for(int i=0;i<countOcccurence;i++){
        cout<<out[i]<<" ";
    }
    return 0;
}