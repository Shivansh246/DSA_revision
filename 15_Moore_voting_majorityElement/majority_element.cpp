#include <bits/stdc++.h>
using namespace std;
int majority(int arr[],int n){
    int ans=arr[0];
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==ans){
            count++;
        }else{
            count--;
            if(count==0){
                ans=arr[i];
            }
        }
    }
    return ans;
}
int main(){
    /*majority element:
    the element which appears more than n/2 amount of time*/
    int arr[]={2,2,1,1,1,2,2};
    int ans = majority(arr,7);
    cout<<ans;
    return 0;
}