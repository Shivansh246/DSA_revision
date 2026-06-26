#include <bits/stdc++.h>
using namespace std;
bool palindrome(int arr[],int n,int i){
    // if(i>=n-1){
    //     return true;
    // }
    // if(arr[i]!=arr[n-1]){
    //     return false;
    // }
    // return palindrome(arr,n-1,i+1);
    if(i>=n-1){
        return true;
    }
    if(arr[i]==arr[n-1]){
        return palindrome(arr,n-1,i+1);
    }else{
        return false;
    }

}
int main(){
    int arr[]={1,2,3,4,3,2,1};
    if(palindrome(arr,7,0)){
        cout<<"Palindrome";
    }else{
        cout<<"Not a palindrome";
    }
    return 0;
}