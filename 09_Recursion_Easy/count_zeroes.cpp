#include <bits/stdc++.h>
using namespace std;
int count(long long int n){
    ///base case
    if(n==0){
        return 0;
    }

    ///recursion
    int small = count(n/10);
    
    ///calculation
    // int last_digit=n%10;
    // if(last_digit==0){
    //     return small+1;
    // }else{
    //     return small;
    // }
    return n%10==0?small+1:small;
}
int main(){
    long long int n;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    } 
    cout<<count(n);
    return 0;
}