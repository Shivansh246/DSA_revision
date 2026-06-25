/*

geometric series for an int k
1+ 1/2+ 1/2^2 + 1/2^3 + 1/2^4 +... 1/2^k*/

#include <bits/stdc++.h>
using namespace std;
double gSum(int n){
    ///base case
    if(n==0){
        return 1;
    }
    ///recursion
    double small = gSum(n-1);

    ///calculation
    return small+ 1.0/pow(2,n);
}
int main(){
    int n;
    cin>>n;
    cout<<gSum(n);
    return 0;
}