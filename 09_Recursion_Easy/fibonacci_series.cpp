#include <iostream>
using namespace std;
int fibonacci(int n){
    ///Base case
    if(n==0) return 0;
    if(n==1) return 1;

    ///recursive case
    int smallernumber1=fibonacci(n-1);
    int smallernumber2 = fibonacci(n-2);

    ///calculation
    return smallernumber1 + smallernumber2;
}
int main(){
    int n;
    cin>>n;
    int ans = fibonacci(n);
    cout<<ans;
    return 0;
}