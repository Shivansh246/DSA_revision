#include <bits/stdc++.h>
using namespace std;
int sod(int n){
    /// base case
    if(n==0){
        return 0;
    }

    ///recursion
    int small = sod(n/10);

    ///calculation
    return small + n%10;

}
int main(){
    int n;
    cin>>n;
    cout<<sod(n);

    return 0;
}