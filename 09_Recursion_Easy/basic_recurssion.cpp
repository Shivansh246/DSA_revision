#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n<0){
        cout<<"Kindly enter a whole number!"<<endl;
        cin>>n;
        return factorial(n);
    }
    if(n==0){
        return 1;
    }
    int smaller = factorial(n-1);
    return n*smaller;
}
int main(){
    int n;
    cin>>n;

    int res=factorial(n);
    cout<<res<<endl;
    return 0;
}