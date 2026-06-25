#include <iostream>
using namespace std;
int count(int n){
    ///base case
    if(n==0){
        return 0;
    }
    /*
    recursion
    int smallans =  count(n-1)
    */
   
   ///calculation
    return count(n/10)+1;
}
int main(){
    int n;
    cin>>n;
    cout<<count(n);
    return 0;
}