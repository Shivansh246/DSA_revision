#include <bits/stdc++.h>
using namespace std;
int countOccurence(int arr[],int n,int x,int i){
    if(i==n){
        return 0;
    }
    if(arr[i]==x){
        return countOccurence(arr,n,x,i+1)+1;
    }
    return countOccurence(arr,n,x,i+1);
}
void countOccurence2(int arr[],int n, int x, int i, int &ans){
    if(i==n){
        return;
    }
    if(arr[i]==x){
        ans++;
    }
    return countOccurence2(arr,n,x,i+1,ans);
}
int main(){
    int arr[]={1,2,4,1,1,1};
    int ans=0;
    cout<<countOccurence(arr,6,1,0);
    countOccurence2(arr,6,1,0,ans);
    cout<<endl<<ans;
    return 0;
}