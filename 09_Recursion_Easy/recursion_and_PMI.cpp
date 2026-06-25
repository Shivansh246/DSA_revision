#include <iostream>
using namespace std;
int fact(int n){
    ///1st step => Base case
    if(n==0){
        return 1;
    }
    ///Induction hypothesis
    int smaller = fact(n-1);/// 2nd step  =>  assumption, recursive case
    int ans = n*smaller;/// 3rd step => Calculation
    return ans; 
}
int main(){
    int n;
    cin>>n;
    cout << fact(n);
    return 0;
}