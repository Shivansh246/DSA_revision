#include<bits/stdc++.h>
using namespace std;
int multiply(int m,int n){
    ///base case
    if(n==0){
        return 0;
    }

    ///recursion
    int small = multiply(m,n-1);

    ///calculation
    return small+m;
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<multiply(m,n);
    return 0;
}